
#include "matrix.h"
#define EPS 0.000000001
using namespace std;

/*
void TaskN1(std::string inp, std::string out){
    std::fstream fin(inp);
	std::ofstream fout(out);
    double k;
	fin>>k;
    int na, ma;
	fin>>na;
	fin>>ma;
    Matrix A(na,ma);
    for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}
	cout<<"A:"<<endl;A.print();cout<<endl;
	int nb, mb;
	fin>>nb;
	fin>>mb;
	Matrix B(nb,mb);
	for(int i=0;i<nb;++i)
	{
		for(int j=0;j<mb;++j)
			{
				fin>>B.at(i,j);
			}
	}
	cout<<"B:"<<endl;B.print();cout<<endl;
	int nc, mc;
	fin>>nc;
	fin>>mc;

	if(nc!=mc)
    {
        fout<<-1;
        fout.close();
        throw InvalidMatrixSize("not square matrix");
    }
	sqMatrix C(nc);
                                                                                                                                                                                                                                                                                                                                                                        Print(inp,out);
    for(int i=0;i<nc;++i)
	{
		for(int j=0;j<mc;++j)
			{
				fin>>C.at(i,j);
			}
	}
	cout<<"C:"<<endl;C.print();cout<<endl;
    sqMatrix D(A.get_rows());
    D = A + (B.Transpose())*(C.Inverse())*k;

	fin.close();
	fout.close();

}

void TaskN2(std::string inp, std::string out){
    std::fstream fin(inp);
	std::ofstream fout(out);
    double k;
	fin>>k;
    int na, ma;
	fin>>na;
	fin>>ma;
    Matrix A(na,ma);
    for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}
	Matrix New(na,ma);
	New=A.FGauss();
                                                                                                                                                                                                                                                                    Print2(inp,out);
	int p=0;
    for(int j=0;j<ma;++j)
    {
        if(New[j][j]!=1)
        {
            p=j;
            break;
        }
    }
    int kol = ma;
    for(int i=0;i<na;++i)
    {
        for(int j=0;j<ma;++j)
        {
            if(New[i][j]!=0)
            {
                kol--;
                break;
            }
        }
    }
    Matrix FSR(na-kol,ma-p);
    for(int j=p;j<ma;++j)
    {
        for(int i=0;i<na;++i)
        {
            if(New[i][j]!=0)
            {
                FSR[i][j]=New[i][j];
            }
        }
    }
	fin.close();
	fout.close();

}

*/
/*
void TaskN3(std::string inp, std::string out){
    std::fstream fin(inp);
	std::ofstream fout(out);
    double k;
	fin>>k;
    int na, ma;
	fin>>na;
	fin>>ma;
    Matrix A(na,ma+1);
    for(int i=0;i<na;++i)
	{
		for(int j=0;j<ma;++j)
			{
				fin>>A.at(i,j);
			}
	}

    for(int i=0;i<na;++i)
    {
        fin>>A.at(i,ma);
    }
    A.FGauss();
    fin.close();
    fout.close();
                                                                                                                                                                                                                                                                                                                                                 Print3(inp,out);

}
*/
int main()
{
     std::vector<vector<double>> m=
    {
        {1,3,-2,0,2,0,0},
        {2,6,-5,-2,4,-3,0},
        {0,0,5,10,0,15,0},
        {2,6,0,8,4,18,0}
    };
    std::vector<vector<double>> m1=
    {
      {1,1,1,2},
      {0,1,1,1},
      {0,0,0,0},
    };
    Matrix mat(2,2);
    mat.ReadAXb("input.txt");
    mat.SolAXb();

	return 0;
}
