#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <exception>

class complejo
{
public:

	complejo(float numR = 0, float numIm = 0, int numIt = 0) : _realNum(numR), _imagNum(numIm), _iterNum(numIt) {
		/*if (numR > 2 || numR < -2 || numIm < -2 || numIm > 2 || numIt < 100 || numIt > 500) {
			throw std::invalid_argument("ERROR");
		}*/
	}

	float realNuum() {
		return _realNum;
	}

	float imgNum() {
		return _imagNum;
	}

	int iterNum() {
		return _iterNum;
	}

	complejo operator+(const complejo& c) const
	{
		float auxReal, auxIm;

		auxReal = _realNum + c._realNum;
		auxIm = _imagNum + c._imagNum;

		return complejo(auxReal, auxIm, _iterNum);
	}

	complejo operator * (const complejo& c)const {
		float nR, nI;

		nR = (_realNum * c._realNum) - (_imagNum * c._imagNum);
		nI = (_realNum * c._imagNum) + (_imagNum * c._realNum);

		return complejo(nR, nI, _iterNum);
	}

	int operator%(const complejo& c)const {
		int sol;

		sol = sqrt((_realNum * _realNum) + (_imagNum * _imagNum));

		return sol;
	}

private:
	float _realNum, _imagNum;
	int _iterNum;
};


inline std::istream& operator>>(std::istream& in, complejo& c) {
	float real, imag;
	int iter;

	std::cin >> real >> imag >> iter;

	c = complejo(real, imag, iter);

	return in;
}

#endif // !COMPLEJO_H
