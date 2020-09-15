#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

namespace lb
{
	class Shape
	{
		public:
		virtual double Perimeter() const = 0;
		virtual double Area() const = 0;
		virtual std::string ToString() const = 0; 
	};

  class Ellipse
  {
    private:
    double radii[2];

    public:
    //Default Constructor
    Ellipse() 
    {
      void setRadii()
      {
        for(int i = 0; i < 2; i++)
        {
          radii[i] = 1;
        }
      }
    }
    //Overloaded Constructor
    Ellipse(double a, double b)
    {
      void getRadii()
      {
        return radii;
      }
      a = radii[1];
      b = radii[2];
    }
    //Copy Constructor
    Ellipse(const Ellipse& obj)
    {
      a = obj.a;
      b = obj.b;
    }
    //Assignment Operator
    Ellipse& operator = (const Ellipse& rhs)
    {
      if(this != &rhs)
      {
        a = rhs.a;
        b = rhs.b;
      }
      return this;
    }
    //Empty Destructor
    ~ Ellipse() {}
    //Overridden Perimeter() Method
    double Perimeter()
    {
      return Perimeter();
    }
    //Overridden Area() Method
    double Area()
    {
      return Area();
    }
    //Overridden ToString() Method
    string ToString const
    {
      stringstream out;
      out << "{" << a << " , " << b << "}"
      return out.str();
    }
    //Friend overloaded ostream operator
    friend ostream& operator << (ostream& out, const Ellipse& obj)
    {
      out << obj.ToString();
      return out;
    }
  }
}

#endif