#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Shape.h"

class Ellipse : public lb::Shape
{
	private:
	double sides[2]; //or double sides[4];

	public:
	Ellipse() 
	{
		sides[0] = 1;
		sides[1] = 1;
	}

	Ellipse(double l,double w)
	{
		sides[0] = l;
		sides[1] = w;
	}

	Ellipse(const Ellipse& obj)
	{
		sides[0] = obj.sides[0];
		sides[1] = obj.sides[1];
	}

	Ellipse& operator=(const Ellipse& rhs)
	{
		if(this != &rhs)
		{
			sides[0] = rhs.sides[0];
			sides[1] = rhs.sides[1];
		}
		return *this;
	}

	~Ellipse() {}

	double Perimeter() const 
	{
		return 3.1415 * (3 * (sides[0] + sides[1]) - sqrt((3 * sides[0] + sides[1]) * (sides[0] + 3 * sides[1])));
	}

	double Area() const 
	{
		return 3.1415 * sides[0] * sides[1];
	}

	std::string ToString() const 
	{
		std::stringstream out;
		
		out << std::setprecision(2) << std::fixed;
		out << "{" << sides[0] << "," << sides[1] << "}";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Ellipse& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
