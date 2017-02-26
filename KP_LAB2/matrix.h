#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#define EPSILON 0.000001
void PrintMatrix(std::vector <std::vector<double>>& vec)
{
    for(int i=0;i<vec.size();++i)
        {
            for(int j=0;j<(*vec.begin()).size();++j)
            {
                std::cout<<vec[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
}
void swapLines(std::vector <std::vector<double>>& vec, int line1, int line2)
{

    vec[line1].swap(vec[line2]);
}
class InvalidMatrixSize : public std::exception {
	std::string reason;

public:
	InvalidMatrixSize() :
		reason("Invalid matrix size")
	{}

	InvalidMatrixSize(std::string _reason) :
		reason(_reason)
	{}

	const char* what() const throw() {
		return reason.c_str();
	}
};

class Matrix {
protected:
	std::vector<std::vector<double>> mtr;
	int rows, cols;
    int numswaps;
public:
	Matrix(int rows, int cols) :
		rows(rows),
		cols(cols)
	{
		std::vector<double> zero(cols);
		for(int i = 0; i < rows; ++i) {
			mtr.push_back(zero);
		}
	}

	Matrix(int rows, int cols, std::vector<std::vector<double>> newMatrix) :
		rows(rows),
		cols(cols)
	{
		for(int i = 0; i < rows; ++i) {
			mtr.push_back(newMatrix[i]);
		}
	}

	void print() {
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				std::cout << mtr[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	double& at(int i, int j) {
		return mtr[i][j];
	}

	double at(int i, int j) const {
		return mtr[i][j];
	}

	std::vector<double>& operator[](int i) {
		return (mtr[i]);
	}

	std::vector<double> operator[](int i) const {
		return (mtr[i]);
	}

	Matrix& operator=(const Matrix& sec) {
		if(rows != sec.rows || cols != sec.cols) {
			throw InvalidMatrixSize("Cannot assign matrices with given dimensions");
		}

		for(int i = 0; i < rows; ++i) {
			mtr[i] = sec.mtr[i];
		}

		return *this;
	}

	Matrix operator+(const Matrix& sec) {
		if(rows != sec.rows || cols != sec.cols) {
			throw InvalidMatrixSize("Cannot add matrices with dimensions");
		}

		std::vector<std::vector<double>> tmp;

		tmp.resize(rows);
		for(int i = 0; i < rows; ++i) {
			tmp[i].resize(cols);
		}

		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				tmp[i][j] = mtr[i][j] + sec.mtr[i][j];
			}
		}

		return Matrix(rows, cols, tmp);
	}

	Matrix operator*(double num) {
		std::vector<std::vector<double>> tmp;

		tmp.resize(rows);
		for(int i = 0; i < rows; ++i) {
			tmp[i].resize(cols);
		}

		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				tmp[i][j] = mtr[i][j] * num;
			}
		}

		return Matrix(rows, cols, tmp);

	}

	Matrix operator*(const Matrix& sec) {

		if(cols != sec.rows) {
			throw InvalidMatrixSize("Cannot multiply matrices with given dimensions");
		}

		std::vector<std::vector<double>> tmp;

		tmp.resize(rows);
		for(int i = 0; i < rows; ++i) {
			tmp[i].resize(sec.cols);
		}

		for(int i = 0; i < rows; ++i) {
			for(int k = 0; k < sec.cols; ++k) {
				int j;
				int sum = 0;
				for(j = 0; j < sec.rows; ++j) {
					sum += mtr[i][j] * sec.mtr[j][k];
				}
				tmp[i][k] = sum;
			}
		}

		return Matrix(rows, sec.cols, tmp);

	}

	Matrix Transpose() {
		std::vector<std::vector<double>> tmp;
		tmp.resize(cols);
		for(int i = 0; i < cols; ++i) {
			tmp[i].resize(rows);
		}

		for(int i = 0; i < cols; ++i) {
			for(int j = 0; j < rows; ++j) {
				tmp[i][j] = mtr[j][i];
			}
		}

		return Matrix(cols, rows, tmp);

	}

	Matrix RowReduce(){
	    numswaps=0;
	    std::vector<std::vector<double>> mat;
	    for(int i=0;i<rows;++i)
        {
            mat.push_back(mtr[i]);
        }

        int rk = std::min(rows,cols);
        for(int row = 0; row < rk; ++row)
        {
            if(mat[row][row])
            {
                // go down the column
                for(int col = 0; col < mat.size(); ++col)
                {
                    if(col != row)
                    {
                        double mult = mat[col][row]*(1.0/mat[row][row]);//ZpMul(mat[col][row], InvMod(mat[row][row], md), md);
                        for(int i = 0; i < mat[0].size(); ++i)
                        {
                            if(fabs(mat[col][i]-(mat[row][i]*mult))>EPSILON)
                            {
                               mat[col][i] = mat[col][i]-(mat[row][i]*mult);
                            }
                            else
                            {
                               mat[col][i]=0;
                            }
                            //ZpSum(mat[col][i], (-1) * ZpMul(mat[row][i], mult, md), md);
                        }
                       /* std::cout<<std::endl;
                        PrintMatrix(mat);
                        std::cout<<std::endl;*/
                    }

                }

            }
            else
            {
                bool reduce = true;
                for(int i = row + 1; i < mat.size(); ++i)
                {
                    if(mat[i][row]!=0)
                    {
                        swapLines(mat, row, i);
                        numswaps++;
                       /* std::cout<<std::endl;
                        PrintMatrix(mat);
                        std::cout<<std::endl;*/
                        reduce = false;
                        break;
                    }
                }

                if(reduce)
                {
                    rk--;
                    for(int i = 0; i < mat.size(); ++i)
                    {
                        mat[i][row] = mat[i][rk];
                    }
                    numswaps++;
                     /*std::cout<<std::endl;
                        PrintMatrix(mat);
                        std::cout<<std::endl;*/
                }
                row--;
            }
        }
        for(int i=0;i<std::min(rows,cols);++i)
        {
            for(int j=i;j<mat[i].size();++j)
            {
                if(mat[i][i])
                {
                    mat[i][j]/=mat[i][i];
                }
            }
        }

        return Matrix(rows,cols,mat);
	}

	friend int Rank(Matrix M){
        Matrix temp (M.rows,M.cols);
        temp = M.RowReduce();
        int rk=0;
        for(int i=0;i<M.rows;++i)
        {
            for(int j=0;j<M.cols;++j)
            {
                if (M.mtr[i][j]!=0)
                {
                    rk++;
                    break;
                }
            }
        }
        return rk;
	}

	friend double Det(Matrix M){
        Matrix temp (M.rows,M.cols);
        temp = M.RowReduce();
        double d=1.0;
        for(int i=0;i<M.rows;++i)
        {
            d*=temp.mtr[i][i];
        }
        d*=pow(-1.0,M.numswaps);
        if(fabs(d)<EPSILON)
        {
            return 0;
        }
        else
        {
            return d;
        }

	}

};


#endif // MATRIX_H_INCLUDED
