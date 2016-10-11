#include "figure.h"

void circle::create_figure(double x,double y, double rad)
{
	center.first=x;
	center.second=y;
	radius = rad;
}

void circle::create_figure()
{
	center.first=0.0;
	center.second=0.0;
	radius = 1.0;
}

std::ostream& operator<<(std::ostream& os,const circle& cr)
{
    os<<"Center: "<<"x= "<<cr.center.first<<" y="<<cr.center.second<<std::endl<<"Radius: "<<cr.radius<<std::endl;

    return os;
}

void circle::move_figure(double x1, double y1)
{
    center.first+=x1;
    center.second+=y1;
}

void circle::rotate_figure(double angle)
{
    center.first=center.first*cos(angle)-center.second*sin(angle);
    center.second=center.first*sin(angle)-center.second*cos(angle);
}
