#include <iostream>
#include <fstream>
#include <armadillo>
using namespace std;
using namespace arma;

int main()
{
	std::fstream fin("input.txt");
	std::ofstream fout("output.txt");
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
	cout<<"A:"<<endl<<A<<endl;
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
	cout<<"B:"<<endl<<B<<endl;
	int nc, mc;
	fin>>nc;
	fin>>mc;
	if(nc!=mc)
	{
		fout<<-1;
		throw InvalidMatrixSize("not square matrix");
	}
	mat C(nc,mc,fill::zeros);
	for(int i=0;i<nc;++i)
	{
		for(int j=0;j<mc;++j)
			{
				fin>>C.at(i,j);	
			}
	}
	cout<<"C:"<<endl<<C<<endl;

	mat D=A+(k*(trans(B)))*inv(C);
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
	return 0;
}
