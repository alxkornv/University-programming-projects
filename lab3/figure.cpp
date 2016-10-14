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
    center.second=center.first*sin(angle)+center.second*cos(angle);
}

void circle::move_n_rotate(double x,double y ,double angle)
{
    move_figure(x,y);
    rotate_figure(angle);
}

void triangle::create_figure()
{
    vertices.clear();
    vertices.push_back(std::make_pair(0,0));
    vertices.push_back(std::make_pair(0,1));
    vertices.push_back(std::make_pair(1,1));
}

void triangle::create_figure(double x1,double y1, double x2, double y2, double x3, double y3)
{
    vertices.clear();
    vertices.push_back(std::make_pair(x1,y1));
    vertices.push_back(std::make_pair(x2,y2));
    vertices.push_back(std::make_pair(x3,y3));
}

void triangle::move_figure(double x1, double y1)
{
    for(int i=0;i<3;i++)
    {
        vertices[i].first+=x1;
        vertices[i].first+=y1;
    }
}
void triangle::rotate_figure(double angle)
{
    for(int i=0;i<3;i++)
    {
        vertices[i].first=vertices[i].first*cos(angle)-vertices[i].second*sin(angle);
        vertices[i].second=vertices[i].first*sin(angle)+vertices[i].second*cos(angle);

    }

}
void triangle::move_n_rotate(double x, double y, double angle)
{
    move_figure(x,y);
    rotate_figure(angle);
}


void triangle::calc_center()
{
    center.first=(vertices[0].first+vertices[1].first+vertices[2].first)/3.0;
    center.second=(vertices[0].second+vertices[1].second+vertices[2].second)/3.0;
}

void triangle::calc_len()
{
    l1=sqrt(pow((vertices[1].first-vertices[0].first),2)+pow((vertices[1].second-vertices[0].second),2));

}
