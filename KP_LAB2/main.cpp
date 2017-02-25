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
	    {6,2,3},
	    {3,1,3.0/2.0},
	    {7,-6,9}
    };
    Matrix mat (3,3,vec);
    std::cout<<Rank(mat);
    std::cout<<std::endl;
    std::cout<<Det(mat);
	return 0;

}
