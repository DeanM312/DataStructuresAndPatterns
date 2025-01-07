#include "Polygon.h"

#include <stdexcept>

using namespace std;

float Polygon::getSignedArea() const {
    float area = 0.0;



    for (size_t i = 0; i < getNumberOfVertices(); i++)
    {
        if (i + 1 < getNumberOfVertices())
        {
            area += (getVertex(i).getX() * getVertex(i + 1).getY() - getVertex(i).getY() * getVertex(i + 1).getX());
        }
        else {
            area += (getVertex(i).getX() * getVertex(0).getY() - getVertex(i).getY() * getVertex(0).getX());
        }
    }










	return area/2.0;


}