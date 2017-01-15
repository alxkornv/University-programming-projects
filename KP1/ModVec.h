#ifndef MODVEC_H_INCLUDED
#define MODVEC_H_INCLUDED
#include <iostream>
#include <cmath>
class ZpVec
{
	private:
	int x,y,z;
	int p;

	public:
    friend ZpVec operator+(const ZpVec& left, const ZpVec& right);
    friend std::ostream& operator<<(std::ostream& os,const ZpVec& Vec);
    friend int ScalarMul(const ZpVec& left, const ZpVec& right);
    friend double VecAngle(const ZpVec& left, const ZpVec& right);
    int VecModule();
    ZpVec operator=(ZpVec Z);
	ZpVec();
	ZpVec(int,int,int,int);

};

	int CheckInput(int a,int p);

    int ZpSum(int a,int b,int p);

	int ZpMul(int a,int b,int p);

	int BinPowMod (int a, int n,int p);

    int InvMod(int a, int p);



#endif // MODVEC_H_INCLUDED
