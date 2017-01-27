#ifndef MODVEC_H_INCLUDED
#define MODVEC_H_INCLUDED
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
class ZpVec
{
	private:
	int x,y,z;
	int p;

	public:
    ZpVec operator*(int);
    friend ZpVec operator+(const ZpVec& left, const ZpVec& right);
    friend std::ostream& operator<<(std::ostream& os,const ZpVec& Vec);

    int ScalarMul(const ZpVec& left, const ZpVec& right);
    double VecModule();
    ZpVec operator=(ZpVec Z);
	ZpVec();
	ZpVec(int,int,int,int);

};
class ZpPoint
{
private:
    int x,y,z;
    int p;
public:
    ZpPoint();
    ZpPoint(int,int,int,int);
    ZpPoint operator*(int);
    friend ZpPoint operator+(const ZpPoint& left, const ZpPoint& right);
    friend ZpPoint operator-(const ZpPoint& left, const ZpPoint& right);
    friend std::ostream& operator<<(std::ostream& os,const ZpPoint& P);

};


    int ZpSum(int a,int b,int p);

	int ZpMul(int a,int b,int p);

	int BinPowMod (int a, int n,int p);

    int InvMod(int a, int p);

    int LinearDep(int,int,int);




#endif // MODVEC_H_INCLUDED
