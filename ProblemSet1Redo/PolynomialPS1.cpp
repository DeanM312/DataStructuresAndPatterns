

#include "Polynomial.h"

using namespace std;


double Polynomial::operator()(double aX) const
{
	double Result = 0;

	for (size_t i = 0; i <= fDegree; i++)
	{
		Result += fCoeffs[i] * pow(aX, i);
	}
	return Result;
}

Polynomial Polynomial::getDerivative() const {
	Polynomial Result;
	for (size_t i = 0; i <= fDegree; i++)
	{
		if (i > 0)
		{
			Result.fCoeffs[i - 1] = fCoeffs[i] * i;
		}
	}

	if (fDegree > 0) {
		Result.fDegree = fDegree - 1;
	}

	return Result;
}


Polynomial Polynomial::getIndefiniteIntegral() const {
	Polynomial Result;
	for (size_t i = 0; i <= fDegree; i++)
	{
		Result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1.0);
	}
	Result.fDegree = fDegree + 1;

	return Result;
}


double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
	double Result;

	Result = getIndefiniteIntegral()(aXHigh) - getIndefiniteIntegral()(aXLow);

	return Result;
}