#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#pragma once
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include<fstream>
#define EPSILON 0.000001
#define EPS 0.0000001
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         #include "amatrix.h"
#define DEBUG 1
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
void put_column_back(std::vector <std::vector<double>>& vec, int col)
{
    std::vector<double> temp;
    for(size_t i=0;i<vec.size();++i)
    {
        temp.push_back(vec[i][col]);
    }

    for(size_t i=0;i<vec.size();++i)
    {
        vec[i].erase(vec[i].begin()+col);
    }
    for(size_t i=0;i<vec.size();++i)
    {
        vec[i].push_back(temp[i]);
    }

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
class InconsistentSystem : public std::exception {
	std::string reason;

public:
	InconsistentSystem() :
		reason("Inconsistent system")
	{}

	InconsistentSystem(std::string _reason) :
		reason(_reason)
	{}

	const char* what() const throw() {
		return reason.c_str();
	}
};
class NotInvertibleMatrix : public std::exception {
	const char* what() const throw() {
		return "Matrix is not invertible";
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

    int get_rows()
    {
        return rows;
    }
    int get_cols()
    {
        return cols;
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

	/*Matrix& operator=(mat& sec){

	    mtr.clear();
	    rows=sec.n_rows;
	    cols=sec.n_cols;
	    mtr.resize(rows);
        for(int i=0;i<rows;++i)
        {
            mtr[i].resize(cols);
            for(int j=0;j<cols;++j)
            {
                mtr[i][j]=sec.at(i,j);
            }
        }

        return *this;
	}*/

	Matrix operator+(const Matrix& sec) {
		if(rows != sec.rows || cols != sec.cols) {
			throw InvalidMatrixSize("Cannot add up matrices with given dimensions");
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
				double sum = 0;
				for(j = 0; j < sec.rows; ++j) {
					sum += mtr[i][j] * sec.mtr[j][k];
				}
				tmp[i][k] = sum;
			}
		}

		return Matrix(rows, sec.cols, tmp);

	}



	void addRow(std::vector<double> newRow) {
		if(newRow.size() != mtr[0].size()) {
			throw InvalidMatrixSize("Invalid row size");
		}

		mtr.push_back(newRow);
		rows++;
	}

	void addCol(std::vector<double> newCol) {
		if(newCol.size() != mtr.size()) {
			throw InvalidMatrixSize("Invalid col size");
		}

		for(int i = 0; i < mtr.size(); ++i) {
			mtr[i].push_back(newCol[i]);
		}
		cols++;
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

	void swapRows(int row1, int row2) {
		for(int i = 0; i < cols; ++i) {
			double tmp = mtr[row1][i];
			mtr[row1][i] = mtr[row2][i];
			mtr[row2][i] = tmp;
		}
	}

	void swapCols(int col1, int col2) {
		for(int i = 0; i < rows; ++i) {
			double tmp = mtr[i][col1];
			mtr[i][col1] = mtr[i][col2];
			mtr[i][col2] = tmp;
		}
	}
	/*
	Matrix RowReduce(){
	    numswaps=0;
	    std::vector<std::vector<double>> mat;
	    for(int i=0;i<rows;++i)
        {
            mat.push_back(mtr[i]);
        }

	int n = (int) mat.size();
	int m = (int) mat[0].size() - 1;

	std::vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		int sel = row;
		for (int i=row; i<n; ++i)
			if (abs (mat[i][col]) > abs (mat[sel][col]))
				sel = i;
		if (abs (mat[sel][col]) < EPS)
			continue;
		for (int i=col; i<=m; ++i)
			std::swap (mat[sel][i], mat[row][i]);
		where[col] = row;

		for (int i=0; i<n; ++i)
			if (i != row) {
				double c = mat[i][col] / mat[row][col];
				for (int j=col; j<=m; ++j)
					mat[i][j] -= mat[row][j] * c;
			}
		++row;
	}
   // PrintMatrix(a);
    for(int i=0;i<rows;++i)
    {
        for(int j=0;j<cols;++j)
        {
            if(mat[i][j]<EPSILON)
            {
                mat[i][j]=0.0;
            }
        }
    }
        return Matrix(rows,cols,mat);
	}*/

	friend int Rank(Matrix M){
        Matrix temp (M.rows,M.cols);
        temp = M.FGauss();
        //temp.print();
        int rk=0;
        for(int i=0;i<M.rows;++i)
        {
            for(int j=0;j<M.cols;++j)
            {
                if (temp.mtr[i][j]!=0)
                {
                    rk++;
                    break;
                }
            }
        }
        return rk;
	}


    Matrix FGauss()
    {
       Matrix res(rows, cols, mtr);
	int lead;
	int rix, iix;
	double lv;
	int rc = rows;

	lead = 0;
	for(rix = 0; rix < rc; ++rix) {
		if(lead >= cols) {
			return res;
		}
		iix = rix;
		while(res[iix][lead] == 0) {
			iix++;
			if(iix == rc) {
				iix = rix;
				lead++;
				if(lead == cols) {
					return res;
				}
			}
		}
		res.swapRows(iix, rix);

		//normalize ROW
		double llv = res[rix][lead];
		for(int i = 0; i < cols; ++i) {
			res[rix][i] /= llv;
		}
        //res.print();
		for(iix = 0; iix < rc; ++iix) {
			if(iix != rix) {
				lv = res[iix][lead];
				//Multiply and subtract
				for(int ix = 0; ix < cols; ++ix) {
					res[iix][ix] += (-1.0) * lv * res[rix][ix];
					if(std::fabs(res[iix][ix]) < EPS) {
						res[iix][ix] = 0.0;
					}
				}

			}
		}
		lead++;
	}

	return res;
    }

    Matrix SolAXb()
    {
        int rankA, rankAb;
        std::ofstream fout("output.txt");
        std::vector<int> freex;//индексы свободных переменных
        for(int i=0;i<cols-1;++i)
        {
            freex.push_back(i);
            #if DEBUG
            std::cout<<freex[i]<<' ';
            #endif // DEBUG
        }

        #if DEBUG
        std::cout<<std::endl;
        #endif

        std::vector<double> a(cols); //частное решение неоднородного
        Matrix mat(rows,cols,mtr);//ЗДЕСЬ РАСШИРЕННАЯ МАТРИЦА!
        rankAb=Rank(mat);
        #if DEBUG
        std::cout<<"ISHODNAYA RASHIRENNAYA MATRICA"<<std::endl;
        mat.print();
         std::cout<<std::endl;
        #endif
        mat=mat.FGauss();
        #if DEBUG
        std::cout<<"POSLE GAUSSA"<<std::endl;;
        mat.print();
        std::cout<<std::endl;
        #endif

        Matrix newmat(rows,cols-1);//ЗДЕСЬ МАТРИЦА БЕЗ СТОЛБЦА СВОБОДНЫХ ЧЛЕНОВ
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols-1;++j)
            {
                newmat[i][j]=mat[i][j];
            }
        }
        rankA=Rank(newmat);
        if(rankA!=rankAb)
        {
            fout<<-1;
            fout.close();
            throw InconsistentSystem("No Solutions");
        }


        for(int i=0;i<rows;++i)
        {
            a[i]=mat[i][cols-1];
        }
        #if DEBUG
        std::cout<<"CHASTNOE RESHENIE"<< ' ';
        for(int i=0;i<cols-1;++i)
        {
            std::cout<<a[i]<<' ';
        }
        std::cout<<std::endl;
        #endif

        int newcols=cols-1;
         #if DEBUG
        std::cout<<"NEWMAT"<<std::endl;
        newmat.print();
        std::cout<<std::endl;
        #endif
        //нашли индексы свободных переменных (исключая не свободные)
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<newcols;++j)
            {
                if (newmat[i][j]!=0.0)
                {
                    std::vector<int>::iterator it;
                    it = find (freex.begin(), freex.end(), j);
                    freex.erase(it);
                    break;
                }
            }
        }
        int colfree = freex.size();//число свободных переменных
        #if DEBUG
        std::cout<<"INDEX SVOBOD"<<std::endl;
        for(int i=0;i<freex.size();++i)
        {
            std::cout<<freex[i]<<' ';
        }
        std::cout<<std::endl;
        #endif



        std::vector<double> zero(newcols);
        std::vector<double> tempx(newcols);

        Matrix res(newcols,colfree+1);//матрица, в которой содержится ФСР, в первом столбце частное решение неоднородной
        //остальные столбцы - фср однородной системы
        for(int i=0;i<newcols;++i)
        {
            res[i][0]=a[i];
        }
        for(int k=0;k<colfree;++k)
        {
            std::vector<double> tempans(newcols);
            tempx=zero;
            tempx[freex[k]]=1;
            tempans = tempx;
            for(int i=0;i<rows;++i)
            {
                for(int j=0;j<newcols;++j)
                {
                    if(newmat[i][j]!=0.0)
                    {
                        for(int v=j+1;v<newcols;++v)
                        {
                            tempans[j]+=(-1)*newmat[i][v]*tempx[v];
                        }
                        break;
                    }
                }
            }

            for(int i=0;i<newcols;++i)
            {
                res[i][k+1]=tempans[i];
            }
        #if DEBUG
        std::cout<<"TEMPANS"<<k<<std::endl;
        for(int i=0;i<tempans.size();++i)
        {
            std::cout<<tempans[i]<<' ';
        }
        std::cout<<std::endl;
        #endif // DEBUG
            tempans.clear();
        }
        std::cout<<std::endl;
        res.print();
        fout<<newcols<<' '<<res.cols-1<<std::endl;
        for(int i=0;i<res.rows;++i)
        {
            for(int j=0;j<res.cols;++j)
            {
                fout<<res[i][j]<<' ';
            }
            fout<<std::endl;
        }
        return res;
    }

	void ReadFromFile(std::string path)
	{
	    std::ifstream fin(path);
        mtr.clear();
        int r;
        int c;
        fin>>r;
        fin>>c;
        rows = r;
        cols = c;
        mtr.resize(r);
        for(int i=0;i<r;++i)
        {
            mtr[i].resize(c);
        }
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;j++)
            {
                fin>>mtr[i][j];
            }
        }
        fin.close();

	}

    bool isSquare() const {
		return (rows == cols);
	}
    void ReadAXb(std::string fname)
    {
        std::ifstream fin(fname);
        mtr.clear();
        int r;
        int c;
        fin>>r;
        fin>>c;
        c++;
        rows = r;
        cols = c;
        mtr.resize(r);
        for(int i=0;i<r;++i)
        {
            mtr[i].resize(c);
        }
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c-1;j++)
            {
                fin>>mtr[i][j];
            }
        }
        for(int i=0;i<r;++i)
        {
            fin>>mtr[i][c-1];
        }
        fin.close();
    }
};
/*
class sqMatrix : public Matrix {
private:

	using Matrix::addRow;
	using Matrix::addCol;

protected:
	int GaussRowSwaps = 0;
public:
	sqMatrix(int dim) : Matrix(dim, dim) {}
	sqMatrix(const Matrix& bmtr) : Matrix(bmtr) {
		if(!bmtr.isSquare()) {
			throw InvalidMatrixSize("Invalid dimensions");
		}
	}
	sqMatrix(int dims, std::vector<std::vector<double>> newMatrix) : Matrix(dims, dims, newMatrix) {
		if(newMatrix.size() != newMatrix[0].size()) {
			throw InvalidMatrixSize("Not square in constructor");
		}
	}

	double Det() {
		GaussRowSwaps = GaussInt();

		double dett = mtr[0][0];
		for(int i = 1; i < rows; ++i) {
			dett *= mtr[i][i];
		}

		if(GaussRowSwaps % 2 != 0) {
			dett *= (-1.0);
		}
        dett=det(Amat());
		return dett;
	}

	sqMatrix Inverse();

};

sqMatrix sqMatrix::Inverse() {
	sqMatrix old(rows, mtr);
	if(old.Det() == 0.0) {
		throw NotInvertibleMatrix();
	}

	Matrix invert(rows, rows, mtr);
	for(int i = 0; i < rows; ++i) {
		std::vector<double> idCol(rows, 0);
		idCol[i] = 1.0;
		invert.addCol(idCol);
	}

	invert = invert.FGauss();

	/*std::cout << std::endl;
	invert.print();
	std::cout << std::endl;*/

/*
	sqMatrix res(rows);
	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < cols; ++j) {
			res.at(i, j) = invert.at(i, cols + j);
		}
	}
    mat sec = inv(Amat());

        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                res.at(i,j)=sec.at(i,j);
            }
        }

	return res;
}
*/
#endif // MATRIX_H_INCLUDED
