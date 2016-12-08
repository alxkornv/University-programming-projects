#include "Part.h"

part::part()
{
	for(int i=0;i<HOLE_NUM;++i)
	{
		hole_set[i].type='*';
		hole_set[i].val=0;
	}

	for(int i=0;i<SIZE_DIM;++i)
	{
		size[i]=1;
	}

	sq_len=0;
	rotation=0;
	for(int i=0;i<VEC_DIM;++i)
	{
		motion[i]=0;
	}

	//координаты задаются от левоой нижней вершины по часовой стрелке
	for (int i=0; i<12;++i)
	{
		coordinates.push_back(std::make_pair(0.0,0.0));
	}
	
}
void part::move(double m1, double m2)
{
	motion[0]+=m1;
	motion[1]+=m2;
}
void part::rotate(double angle)
{
	rotation+=angle;
}
void part::set_sq_len(double len)
{
	sq_len=len;
}

void part::set_size(double size0, double size1)
{
	size[0]=size0;
	size[1]=size1;
}

void part::set_hole(int num,char hole_type,double hole_value)
{
	if (num<=4)
	{
	hole_set[num-1].type=hole_type;
	hole_set[num-1].val=hole_value;
	}
	else
		std::cout<<"Bad hole number";//лучше было сделать эксепшн
}
void part::calculate_coord()
{
	double x_c=size[0]/2+motion[0];
	double y_c=size[1]/2+motion[1];
	for(int i=0;i<12;++i)
	{
		coordinates.at(i).first+=motion[0];
		coordinates.at(i).second+=motion[1];
		if(rotation!=0){
		coordinates.at(i).first=x_c+(coordinates.at(i).first-x_c)*cos(rotation)-(coordinates.at(i).second-y_c)*sin(rotation);
		coordinates.at(i).second=y_c+(coordinates.at(i).second-y_c)*cos(rotation)+(coordinates.at(i).first-x_c)*sin(rotation);
		}
	}
}
void part::place_on_surface()
{
	
	if(hole_set[0].type!='*')
	{
		coordinates.at(0).first=hole_set[0].val;
		coordinates.at(1).second=hole_set[0].val;
	}
	else
	{
		coordinates.at(0)=std::make_pair(0.0,0.0);
		coordinates.at(1)=coordinates.at(0);
	}
	if(hole_set[1].type!='*')
	{
		coordinates.at(2).second=size[1]-hole_set[1].val;

		coordinates.at(3).first=hole_set[1].val;
		coordinates.at(3).second=size[1];
	}
	else
	{
		coordinates.at(2)=std::make_pair(0.0,size[1]);
		coordinates.at(3)=coordinates.at(2);
	}
	if(hole_set[2].type!='*')
	{
		coordinates.at(4)=std::make_pair(size[0]-hole_set[2].val,size[1]);
		coordinates.at(5)=std::make_pair(size[0],size[1]-hole_set[2].val);
	}
	else
	{
		coordinates.at(4)=std::make_pair(size[0],size[1]);
		coordinates.at(5)=coordinates.at(4);
	}
	if(hole_set[3].type!='*')
	{
		coordinates.at(6)=std::make_pair(size[0],hole_set[3].val);
		coordinates.at(7)=std::make_pair(size[0]-hole_set[3].val,0);
	}
	else
	{
		coordinates.at(6)=std::make_pair(size[0],0);
		coordinates.at(7)=coordinates.at(6);
	}
	

	coordinates.at(8)=std::make_pair(size[0]/2+sq_len/2,0);
	coordinates.at(9)=std::make_pair(size[0]/2+sq_len/2,sq_len);
	coordinates.at(10)=std::make_pair(size[0]/2-sq_len/2,sq_len);
	coordinates.at(11)=std::make_pair(size[0]/2-sq_len/2,0);
}
bool part::part_existance()//много хардкодинга и похожего кода, следует сгруппировать условия по функциям
{
	bool result;
	if(sq_len>=size[0] || sq_len>=size[1])
	{
		return false;
	}

	for(int i=0;i<HOLE_NUM;++i)
	{
		if(hole_set[i].val>=size[0] || hole_set[i].val>=size[1])
		{
			return false;
		}
	}

	if(hole_set[0].type!='*')
	{
		if(hole_set[0].val > (size[0]-sq_len)/2.0)//пересечение с квадратом
		{
			return false;
		}
		if(hole_set[0].val>=(size[1]-hole_set[1].val))//пересечение с верхним соседом
		{
			return false;
		}
		if(hole_set[0].val>(size[0]-hole_set[3].val))//пересечение с соседом справа (нужно только если квадрат отсутсвует)
		{
			return false;
		}
		//пересечение с соседом по диагонали (только если отверстие является круглым)
		//если оба отверстия треугольные и деталь квадратная, то при их рересечении выполнится условие 2, деталь - прямоугольная -никогда не пересекутся
		if(hole_set[0].type=='C')
		{
			if(hole_set[3].type=='C')
			{
				if((hole_set[0].val+hole_set[3].val)*(hole_set[0].val+hole_set[3].val)>=size[0]*size[0]+size[1]*size[1])//сумма радиусов больше или равна диагонали прямоугольника
				{
					return false;
				}
				
			}
			

		}
	}
	
	return true;
}