
#include "Polygon.h"

#include <stdexcept>

using namespace std;


float Polygon::getSignedArea() const
{
	float Result = 0.0;

	for (size_t i = 0; i < fNumberOfVertices; i++)
	{
		if (i < fNumberOfVertices-1)
		{
			Result += (fVertices[i].getX() * fVertices[i + 1].getY() - fVertices[i].getY() * fVertices[i + 1].getX());
		}
		else
		{
			Result += (fVertices[i].getX() * fVertices[0].getY() - fVertices[i].getY() * fVertices[0].getX());
		}
	}

	return Result/2;
}