#pragma once
#ifndef R2GRAPH_H
#define R2GRAPH_H
#include <cmath>
#include <iostream>
const double R3GRAPH_EPSILON = 0.0000001;

class R3Vector
{
public:
	double x;
	double y;
	double z;
	R3Vector()
	{
		x=0.0;
		y=0.0;
		z=0.0;
	}

	R3Vector(double xx, double yy, double zz)
	{
		x=xx;
		y=yy;
		z=zz;
	}

	~R3Vector() 
	{}

	R3Vector(const R3Vector& v)
	{
		x=v.x;
		y=v.y;
		z=v.z;
	}

	R3Vector& operator=(const R3Vector& v)
	{
		x=v.x;
		y=v.y;
		z=v.z;
		return *this;
	}

	R3Vector operator+(const R3Vector& v) const 
	{
		return R3Vector(x + v.x, y + v.y,z+v.z);
	}

	R3Vector& operator+=(const R3Vector& v) 
	{
		x+=v.x;
		y+=v.y;
		z+=v.z;
		return *this;
	}

	R3Vector operator-(const R3Vector& v) const 
	{
		return R3Vector(x - v.x, y - v.y,z-v.z);
	}

	R3Vector& operator-=(const R3Vector& v) 
	{
		x-=v.x;
		y-=v.y;
		z-=v.z;
		return *this;
	}

	R3Vector operator*(double c) const 
	{
		return R3Vector(x*c, y*c,z*c);
	}

	R3Vector& operator*=(double c) 
	{
		x*=c;
		y*=c;
		z*=c;
		return *this;
	}

	double operator*(const R3Vector& v) const // Scalar product
	{ 
		return x*v.x + y*v.y + z*v.z;
	}

	

	double length() const 
	{
		return sqrt(x*x + y*y+z*z);
	}

	R3Vector& normalize() {
		double l = length();
		if (l >= R3GRAPH_EPSILON)
		{
			x /= l;
			y /= l;
			z /= l;
		}
		return *this;
	}

	R3Vector normal() const
	{
		return R3Vector(1,1,(-1)*(x+y)/z);
	}

	double angle(const R3Vector& v) const
	{
		return std::acos( ((*this)*v) / (((*this).length()) * (v.length())) );
	}

	friend std::ostream& operator<<(std::ostream& os, const R3Vector& v)
	{
		os<<'('<<v.x<<','<<v.y<<','<<v.z<<')';
		return os;
	}

	bool operator==(const R3Vector& v) const
	{
		return (
			fabs(x - v.x) <= R3GRAPH_EPSILON &&
			fabs(y - v.y) <= R3GRAPH_EPSILON &&
			fabs(z - v.z) <= R3GRAPH_EPSILON
			);
	}
	bool operator!=(const R3Vector& v) const { return !operator==(v); }
	friend R3Vector CrossProduct(const R3Vector& u, const R3Vector& v) 
	{
		double x1,y1,z1;
		double x2,y2,z2;

		x1=u.x;
		y1=u.y;
		z1=u.z;

		x2=v.x;
		y2=v.y;
		z2=v.z;

		return R3Vector(y1*z2-z1*y2,(-1)*(x1*z2-z1*x2),z1*y2-y1*x2);

	}


	friend double MixedProduct(const R3Vector& u, const R3Vector& v,const R3Vector& h) 
	{
		return u*CrossProduct(v,h);
	}
};

inline R3Vector operator*(double c, const R3Vector& v) 
{
	return R3Vector(c*v.x, c*v.y,c*v.z);
}


//--------------------------------------------------------------------------
class R3Point  {
public:
	double x;
	double y;
	double z;

	R3Point() :                         // Default constructor
		x(0.),
		y(0.),
		z(0.)
	{}

	R3Point(const R3Point& p) :        // Copy-constructor
		x(p.x),
		y(p.y),
		z(p.z)
	{}

	R3Point(double xx, double yy, double zz) :
		x(xx),
		y(yy),
		z(zz)
	{}

	R3Point& operator=(const R3Point& p) {    // Copy-operator
		x = p.x; y = p.y; z = p.z;
		return *this;
	}

	~R3Point() {}                              // Destructor

	R3Point operator+(const R3Point& p) const {
		return R3Point(x + p.x, y + p.y,z+p.z);
	}

	R3Point operator+(const R3Vector& v) const {
		return R3Point(x + v.x, y + v.y,z+v.z);
	}

	R3Point& operator+=(const R3Point& p) {
		x += p.x;
		y += p.y;
		z += p.z;
		return *this;
	}

	R3Point& operator+=(const R3Vector& v) {
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	R3Vector operator-(const R3Point& p) const {
		return R3Vector(x - p.x, y - p.y,z-p.z);
	}

	R3Point operator-(const R3Vector& v) const {
		return R3Point(x - v.x, y - v.y,z-v.z);
	}

	R3Point& operator-=(const R3Vector& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	R3Point& operator-=(const R3Point& p) {
		x -= p.x;
		y -= p.y;
		z -= p.z;
		return *this;
	}

	R3Point operator*(double c) const {
		return R3Point(x*c, y*c,z*c);
	}

	R3Point& operator*=(double c) {
		x *= c;
		y *= c;
		z *= c;
		return *this;
	}
	double operator*(const R3Vector& v) const // Scalar product
	{ 
		return x*v.x + y*v.y + z*v.z;
	}
	// Comparings
	bool operator==(const R3Point& p) const {
		//... return (x == p.x && y == p.y);
		return (
			fabs(x - p.x) <= R3GRAPH_EPSILON &&
			fabs(y - p.y) <= R3GRAPH_EPSILON &&
			fabs(z - p.z) <= R3GRAPH_EPSILON
			);
	}
	bool operator!=(const R3Point& p) const { return !operator==(p); }

	friend std::ostream& operator<<(std::ostream& os, const R3Point& p)
	{
		os<<'('<<p.x<<','<<p.y<<','<<p.z<<')';
		return os;
	}

	friend double area(const R3Point& a, const R3Point& b, const R3Point& c)
	{
		R3Vector vec1((b-a).x,(b-a).y,(b-a).z);
		R3Vector vec2((c-a).x,(c-a).y,(c-a).z);

		return CrossProduct(vec1,vec2).length()*0.5;
	}

	friend double distance(const R3Point& a, const R3Point& b)
	{
		return R3Vector((b-a).x,(b-a).y,(b-a).z).length();
	}
};

inline R3Point operator*(double c, const R3Point& p) {
	return R3Point(c*p.x, c*p.y,c*p.z);
}

inline double operator*(R3Vector& v, R3Point& p)
{
	return v.x*p.x + v.y*p.y + v.z*p.z;
}


























#endif
