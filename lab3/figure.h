#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED
#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <cmath>
class figure
 {
public:
	figure(){};
	virtual~figure(){};

	virtual void create_figure() = 0;
	virtual void move_figure(double,double) = 0;
	virtual void rotate_figure(double) = 0;

private:
protected:
	int Vertex_num;
};

class circle : public figure
{
public:
	circle(){};
	~circle(){};

	void create_figure(double,double , double );
	void create_figure();
	void move_figure(double,double);
	void rotate_figure(double);
    friend std::ostream& operator<<(std::ostream& os,const circle& cr);

private:
	std::pair<double,double> center;
	double radius;
};

class triangle : public figure
{
public:
	triangle();
	~triangle();

	void create_figure();
	void create_figure(double,double , double );
	void move_figure(double,double);
	void rotate_figure(double);
private:
	std::pair<int,int> center;
	std::vector <std::pair<int,int>> vertices;
};



class rectangle : public figure
{
public:
	rectangle();
	~rectangle();

	void create_figure();
	void move_figure();
	void rotate_figure();
private:
	std::pair<int,int> center;
	std::vector <std::pair<int,int>> vertices;
};




#endif // FIGURE_H_INCLUDED
