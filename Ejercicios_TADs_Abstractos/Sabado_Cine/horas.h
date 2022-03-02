#ifndef HORAS_H
#define HORAS_H

// INCLUDES

#include <iostream>
#include <iomanip>
#include <stdexcept> // invalid_argument

class horas
{
private:
    int _hours, _minutes, _seconds;

public:
    horas(int h = 0, int m = 0, int s = 0)
    {
        if (!valid(h, m, s))
        {
            throw std::invalid_argument("ERROR\n");
        }
        else
        {
            _hours = h;
            _minutes = m;
            _seconds = s;
        }
    }

    // OBSERVERS

    int hour()
    {
        return _hours;
    }

    int minutes()
    {
        return _minutes;
    }

    int seconds()
    {
        return _seconds;
    }

    bool valid(int h, int m, int s) const
    {
        return 0 <= h && h < 24 && 0 <= m && m < 60 && 0 <= s && s < 60;
    }

    // OPERATORS
    bool operator<(const horas &h) const
    {
        return 3600 * _hours + 60 * _minutes + _seconds <
               3600 * h._hours + 60 * h._minutes + h._seconds;
    }

    bool operator>(const horas &h) const
    {
        return 3600 * _hours + 60 * _minutes + _seconds >
               3600 * h._hours + 60 * h._minutes + h._seconds;
    }

    horas operator+(const horas &h) const
    {
        int auxSec = 0;
        int auxMin = 0;
        int auxHour = 0;
        auxSec += _seconds + h._seconds;
        if (auxSec > 59)
        {
            auxMin++;
            auxSec -= 60;
        }
        auxMin += _minutes + h._minutes;
        if (auxMin > 59)
        {
            auxHour++;
            auxMin -= 60;
        }
        auxHour += _hours + h._hours;
        if (auxHour > 23)
        {
            throw std::invalid_argument("Days have only 24 hours");
        }
        return horas(auxHour, auxMin, auxSec);
    }

    bool operator==(const horas &h) const
    {
        return _hours == h._hours && _minutes == h._minutes && _seconds == h._seconds;
    }

    bool operator!=(const horas &h) const
    {
        return !(*this == h);
    }

    // PRINT
    void print(std::ostream &out = std::cout) const
    {

        out << std::setfill('0') << std::setw(2) << _hours << ':'
            << std::setfill('0') << std::setw(2) << _minutes << ':'
            << std::setfill('0') << std::setw(2) << _seconds;
    }

    void read(std::istream &input = std::cin)
    {
        int h, m, s;
        char c;
        input >> h >> c >> m >> c >> s;
        *this = horas(h, m, s);
    }
};

// IN / OUT

inline std::ostream &operator<<(std::ostream &out, horas const &hour)
{
    hour.print(out);
    return out;
}

inline std::istream &operator>>(std::istream &entrada, horas &h)
{
    h.read(entrada);
    return entrada;
}

#endif
