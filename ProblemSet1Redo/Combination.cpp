


#include "Combination.h"

using namespace std;


Combination::Combination(size_t aN, size_t aK) : fN(aN), fK(aK)
{

}

size_t Combination::getN() const
{
	return fN;
}
size_t Combination::getK() const 
{
	return fK;
}


unsigned long long Combination::operator()() const
{
	unsigned long long Result = 1;

	for (size_t k = 1; k < fK+1; k++)
	{
		Result *= (fN - (k - 1.0)) / k;
	}

	return Result;
}