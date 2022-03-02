#ifndef PELICULA_H
#define PELICULA_H

// INCLUDES 
#include <string>
#include <iostream>
#include "horas.h"

class pelicula
{
public:
	// Constructor
	pelicula(horas hourI = 0, horas dur = 0, std::string title = ""): _initHour(hourI), _duration(dur), _title(title) {
		_endHour = hourI + dur;
	}

	// OBSERVERS

	horas initHour() {
		return _initHour;
	}

	horas duration() {
		return _duration;
	}

	horas endHour() {
		return _endHour;
	}

	std::string title() {
		return _title;
	}


	void print(std::ostream& out = std::cout) const
	{
		std::cout << _endHour << " " << _title;
	}

	bool operator<(const pelicula& p) {
		if (_endHour == p._endHour) {
			return _title < p._title;
		}
		return _endHour < p._endHour;
	}

private:
	horas _initHour, _duration, _endHour;
	std::string _title;
};

// OUT

inline std::ostream& operator<<(std::ostream& out, pelicula const& film)
{
	film.print(out);
	return out;
}


#endif // !PELICULA_H


