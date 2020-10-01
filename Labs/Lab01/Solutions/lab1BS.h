#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Point3D
{
	private:
	double p[3];
	
	public:
	Point3D() 
	{
		p[0] = 0;
		p[1] = 0;
		p[2] = 0;
	}

	Point3D(double x,double y,double z) 
	{
		p[0] = x;
		p[1] = y;
		p[2] = z;
	}

	Point3D(const Point3D& obj) 
	{
		p[0] = obj.p[0];
		p[1] = obj.p[1];
		p[2] = obj.p[2];
	}

	Point3D& operator(const Point3D& rhs) 
	{
		if(this != &rhs)
		{
			p[0] = rhs.p[0];
			p[1] = rhs.p[1];
			p[2] = rhs.p[2];
		}
		return *this;
	}

	~Point3D() {}

	double GetX() const 
	{
		return p[0];
	}
	
	double GetY() const 
	{
		return p[1];
	}
	
	double GetZ() const 
	{
		return p[2];
	}
	
	void SetX(double v) 
	{
		p[0] = v;
	}

	void SetY(double v) 
	{
		p[1] = v;
	}

	void SetZ(double v) 
	{
		p[2] = v;
	}

	std::string ToString() const 
	{
		std::stringstream out;

		out << std::setprecision(2) << fixed;
		out << "(" << p[0] << "," << p[1] << "," << p[2] << ")";
		return out.str();
	}

	friend std::ostream& operator<<(std::ostream& out,const Point3D& obj)
	{
		out << obj.ToString();
		return out;
	}
};

#endif
