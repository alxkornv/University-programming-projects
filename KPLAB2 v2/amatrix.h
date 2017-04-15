#ifndef AMATRIX_H_INCLUDED
#define AMATRIX_H_INCLUDED
#define ARMA_DONT_PRINT_ERRORS
#include<armadillo>
using namespace arma;
#include <iostream>
#include <fstream>
#include <armadillo>
#include <cmath>
using namespace std;
using namespace arma;
class InvalidMatrixSize2 : public std::exception {
	std::string reason;

public:
	InvalidMatrixSize2() :
		reason("Invalid matrix size")
	{}

	InvalidMatrixSize2(std::string _reason) :
		reason(_reason)
	{}

	const char* what() const throw() {
		return reason.c_str();
	}
};
void Print(string inp, string out)
{
	std::fstream fin(inp);
	std::ofstream fout(out);
	double k;
	fin>>k;
	int na, ma;
	fin>>na;
	fin>>ma;
	mat A(na,ma,fill::zeros);
	for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}
	//cout<<"A:"<<endl<<A<<endl;
	int nb, mb;
	fin>>nb;
	fin>>mb;
	mat B(ma,mb,fill::zeros);
	for(int i=0;i<nb;++i)
	{
		for(int j=0;j<mb;++j)
			{
				fin>>B.at(i,j);
			}
	}
	//cout<<"B:"<<endl<<B<<endl;
	int nc, mc;
	fin>>nc;
	fin>>mc;
	if(nc!=mc)
	{
		fout<<-1;
		throw InvalidMatrixSize2("not square matrix");
	}
	mat C(nc,mc,fill::zeros);
	for(int i=0;i<nc;++i)
	{
		for(int j=0;j<mc;++j)
			{
				fin>>C.at(i,j);
			}
	}
	//cout<<"C:"<<endl<<C<<endl;
    if(det(C)==0)
    {
        fout<<-1;
        fout.close();
        throw InvalidMatrixSize2("not invertible matrix");
    }
	mat D=A+(k*(trans(B)))*inv(C);
	cout<<k*(trans(B)*inv(C))<<endl;;
	if(D.n_rows!=0 && D.n_cols!=0)
	{
		fout<<1;
		fout<<'\n';
		fout<<det(D)<<'\n';
		fout<<D.n_rows<<' '<<D.n_cols<<'\n';
		for(int i=0;i<D.n_rows;++i)
			{
				for(int j=0;j<D.n_cols;++j)
					{
						fout<<D.at(i,j)<<' ';
					}
				fout<<'\n';
			}
	}
	else
	cout<<-1;
	fin.close();
	fout.close();

}

void Print2(string inp, string out)
{
    std::fstream fin(inp);
	std::ofstream fout(out);
	int na, ma;
	fin>>na;
	fin>>ma;
	mat A(na,ma,fill::zeros);
	for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}

	mat R = null(A);
	if(R.n_rows==0 || R.n_cols==0)
    {
        fout<<0<<' ';
        fout<<R.n_rows;
    }
    else
    {
        fout<<R.n_cols<<' '<<R.n_rows<<'\n';
        for(int i = 0; i<R.n_rows;++i)
        {
            for(int j = 0;j<R.n_cols;++j)
            {
                if(fabs(R.at(i,j))<EPSILON)
                {
                    R.at(i,j)=0.0;
                }
                fout<<R.at(i,j)<<' ';
            }
            fout<<'\n';
        }
    }
    fin.close();
    fout.close();
}

void Print3(string inp, string out)
{
    std::fstream fin(inp);
	std::ofstream fout(out);
	int na, ma;
	fin>>na;
	fin>>ma;
	mat A(na,ma,fill::zeros);
	for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}
    //cout<<A<<endl;
	vec b(na);
    for(int i=0;i<na;++i)
    {
        fin>>b.at(i);
    }
    cout<<b<<endl;
    mat R = null(A);
    if(R.n_rows==0 || R.n_cols==0)
    {
        fout<<0<<' ';
    }
    vec R1 = solve(A,b);
    fout<<A.n_cols<<' '<<R.n_cols<<'\n';
    //fout<<R1<<'\n';
    for(int i=0;i<R1.n_elem;++i)
    {
        fout<<R1.at(i)<<'\n';
    }
    fout<<'\n';
    //fout<<R;
    for(int i = 0; i<R.n_rows;++i)
        {
            for(int j = 0;j<R.n_cols;++j)
            {
                fout<<R.at(i,j)<<' ';
            }
            fout<<'\n';
        }
    fin.close();
    fout.close();
}
#endif // AMATRIX_H_INCLUDED
