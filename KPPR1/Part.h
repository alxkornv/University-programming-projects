#pragma once

#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
typedef struct 
{
	char type;//'R' - round hole, 'T' - triangular hole, '*' - no hole
	double val;
}hole;

typedef struct 
{
	double x,y;
}point;

class part
{
	public:
	part();
	void set_sq_len(double);
	void set_size(double,double);
	void set_hole(int,char,double);//number of vertice(1-4), type of hole "C", "T", value
	void move(double,double);
	void rotate(double);
	void place_on_surface();//устанавливает деталь в угол первого квадранта
	void calculate_coord();
	bool part_existance();

	private:
	static const int SIZE_DIM=2;
	static const int HOLE_NUM=4;
	static const int VEC_DIM=2;
	hole hole_set[HOLE_NUM];	
	double size[SIZE_DIM];//size[0]-length, size[1]-height
	double sq_len;
	double rotation;
	double motion[VEC_DIM];
	std::vector<std::pair<double,double>> coordinates;
};