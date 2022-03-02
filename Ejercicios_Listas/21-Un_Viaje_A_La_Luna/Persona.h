#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
#include <stdexcept>

class persona
{
public:
    persona();
    persona(std::string fullName, int age);
    ~persona();

    std::string fullName();
    int age();

    void read(std::istream &input);
    void print(std::ostream &out) const;

private:
    std::string _fullName;
    int _age;
};

persona::persona()
{
}

persona::persona(std::string fullName, int age) : _fullName(fullName), _age(age)
{
    if (age < 0)
    {
        throw std::invalid_argument("Invalid age");
    }
}

persona::~persona()
{
}

inline std::string persona::fullName()
{
    return this->_fullName;
}

inline int persona::age()
{
    return this->_age;
}

void persona::read(std::istream &input = std::cin)
{
    std::string fn;
    int a;
    input >> a;
    input >> std::ws;
    getline(input, fn);
    *this = persona(fn, a);
}

void persona::print(std::ostream &out = std::cout) const
{
    out << _fullName;
}

inline std::istream &operator>>(std::istream &entrada, persona &p)
{
    p.read(entrada);
    return entrada;
}

inline std::ostream &operator<<(std::ostream &out, persona const &p)
{
    p.print(out);
    return out;
}

class condition
{

private:
    int min, max;

public:
    condition(int mi, int ma)
    {
        this->min = mi;
        this->max = ma;
    }

    bool operator()(persona p)
    {
        return (p.age() < this->min || p.age() > this->max);
    }
};
#endif // !PERSONA_H
