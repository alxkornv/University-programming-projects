
#include "matrix.h"

typedef std::vector<std::vector<double>> VVD;

int main() {

	/*CMTR vec1 = {
		{1, 1},
		{1, 1},
		{1, 1},
	};

	CMTR vec2 = {
		{1, 2, 1},
		{1, 2, 1},
	};

	Matrix mtr1(3, 2, vec1);
	Matrix mtr2(2, 3, vec2);

	Matrix mtr3 = mtr1 * mtr2;
	mtr3.print();

	std::cout << std::endl;
	Matrix mtr4 = mtr2.Transpose();
	mtr4.print();*/

	VVD vec = {
	    {1,-8,1,-9},
	    {1,-4,-1,-5},
	    {-3,2,8,5},
	    {5,2,2,3},

    };
    Matrix mat (4,4,vec);
    mat.RowReduce().print();

	return 0;

}
