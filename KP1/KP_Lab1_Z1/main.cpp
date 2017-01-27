#include "VectorR3.h"

double PointPlainDist(R3Point&,R3Point&,R3Vector&);

double LinesDist(R3Point&,R3Vector&,R3Point&,R3Vector&);

bool Coplanarity(R3Vector&,R3Vector&,R3Vector&);
int main()
{ 
	//angle
	R3Vector a(0,0,1);
	R3Vector b(0,1,0);
	std::cout<<a.angle(b)<<std::endl;
	//point to plain distance
	R3Point A(1,1,1);//Any point
	//Plain set
	R3Point p1(0,0,0);
	R3Vector v1(0,0,1);
	double dist=PointPlainDist(A,p1,v1);
	std::cout<<"Distance = "<<dist<<std::endl;

	//distance between lines

	//first line
	R3Point r1(1,2,3);
	R3Vector s1(4,5,6);
	//second line
	R3Point r2(9,8,7);
	R3Vector s2(6,5,4);

	std::cout<<std::endl<<LinesDist(r1,s1,r2,s2);
	return 0;
}

double PointPlainDist(R3Point& A,R3Point& p1,R3Vector& v1)
{
	return fabs(A*v1+(-1)*(p1*v1))/v1.length();//d=(A*x+B*y+C*z)/Sqrt(A^2+B^2+C^2), (A,B,B) - normal vector, (x,y,z) - point vector
}

double LinesDist(R3Point& r1,R3Vector& s1,R3Point& r2,R3Vector& s2)
{
	R3Vector s0((r2-r1).x,(r2-r1).y,(r2-r1).z);
	return MixedProduct(s0,s1,s2)/CrossProduct(s1,s2).length();
}

bool Coplanarity(R3Vector& v1,R3Vector& v2,R3Vector& v3)
{
	if(MixedProduct(v1,v2,v3)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}