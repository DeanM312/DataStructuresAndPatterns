#include "BernsteinBasisPolynomial.h"

#include <stdexcept>

using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(aN, aV) {
	
}


double BernsteinBasisPolynomial::operator()(double aX) const
{
	double Result = 0.0;
	
	Result = fFactor() * pow(aX, fFactor.getK()) * pow(1.0 - aX, fFactor.getN() - fFactor.getK());
	
	return Result;
}