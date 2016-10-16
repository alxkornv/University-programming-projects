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
	virtual void move_n_rotate(double,double,double)=0;

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
	void move_n_rotate(double,double,double);
    friend std::ostream& operator<<(std::ostream& os,const circle& cr);

private:
	std::pair<double,double> center;
	double radius;
};

class triangle : public figure
{
public:
	triangle(){};
	~triangle(){};

	void create_figure();
	void create_figure(double,double ,double,double,double ,double );
	void move_figure(double,double);
	void rotate_figure(double);
	void move_n_rotate(double,double,double);
	void calc_center();
	void calc_len();
	friend std::ostream& operator<<(std::ostream& os,const triangle& tr);
private:
    std::pair<double,double> center;

	std::vector <std::pair<double,double>> vertices;
	double l1,l2,l3;
};



class rectangle : public figure
{
public:
	rectangle(){};
	~rectangle(){};

	void create_figure();
	void create_figure(double,double,double,double,double,double,double,double);
	void move_figure(double,double);
	void rotate_figure(double);
	void move_n_rotate(double,double,double);
	void calc_len();
	void calc_center();
	friend std::ostream& operator<<(std::ostream& os,const rectangle& tr);
private:
    double l1,l2,l3,l4;
	std::pair<double,double> center;
	std::vector <std::pair<double,double>> vertices;
};




#endif // FIGURE_H_INCLUDED
