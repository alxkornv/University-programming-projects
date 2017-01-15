#include "ModVec.h"

int CheckInput(int a,int p)
{
    if(p<0 || ((a>p) || (a<(-1)*p)))
    {
        std::cout<<"Bad input";
        return -1;
    }
    if(a<0)
    {
        a=p+a;
    }
    return a;
}

int ZpSum(int a,int b,int p)
{
    a=CheckInput(a,p);
    b=CheckInput(b,p);
    if((a == -1) || (b == -1))
    {
        return -1;
    }
    return (a+b)%p;
}
int ZpMul(int a,int b,int p)
{
    a=CheckInput(a,p);
    b=CheckInput(b,p);
    if((a == -1) || (b == -1))
    {
        return -1;
    }
    return (a*b)%p;
}
int BinPowMod (int a, int n,int p)
{
int res = 1;
while (n)
    if (n & 1)
    {
        res = ZpMul(res,a,p);
        --n;
    }
    else
    {
        a = ZpMul(a,a,p);
        n >>= 1;
    }
return res;
}

int InvMod(int a, int p)
{
    return BinPowMod(a,p-2,p);
}
//------------------------------------------------------------
 ZpVec::ZpVec()
{
    x=0;
    y=0;
    z=0;
    p=0;
}

ZpVec::ZpVec(int X_coordinate,int Y_coordinate,int Z_coordinate,int Mod_base)
{
  x=X_coordinate;
  y=Y_coordinate;
  z=Z_coordinate;
  p=Mod_base;
}

ZpVec operator+(const ZpVec& left, const ZpVec& right)
{
    return ZpVec(ZpSum(left.x,right.x,left.p),ZpSum(left.y,right.y,left.p),ZpSum(left.z,right.z,left.p),left.p);
}

ZpVec ZpVec::operator=(ZpVec Z)
{
    x=Z.x;
    y=Z.y;
    z=Z.z;
    p=Z.p;
    return *this;
}

std::ostream& operator<<(std::ostream& os,const ZpVec& Vec)
{
    os<<'('<<Vec.x<<','<<Vec.y<<','<<Vec.z<<')'<<" mod "<<Vec.p<<std::endl;
    return os;
}

int ScalarMul(const ZpVec& left, const ZpVec& right)
{
    return (ZpMul(left.x,right.x,left.p)+ZpMul(left.y,right.y,left.p)+ZpMul(left.z,right.z,left.p))%left.p;
}

double ZpVec::VecModule()
{
    return sqrt(x^2+y^2+z^2);
}


















