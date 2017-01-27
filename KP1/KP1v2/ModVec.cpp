#include "ModVec.h"


int ZpSum(int a,int b,int p)
{
    int res=(a+b)%p;
    if(res<0)
    {
        res=p+res;
    }
    return res;
}
int ZpMul(int a,int b,int p)
{
    int res=(a*b)%p;
    if(res<0)
    {
        res=p+res;
    }
    return res;
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

int LinearDep(int R,int C, int module)
{

    int temp;
    int mat [R][C];
    int M=std::min(R,C);
    for (int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            std::cin>>temp;
            mat[i][j]=temp;
        }
    }
    //
    for (int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            std::cout<<mat[i][j]<<' ';
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    //
    for(int r=0;r<C;r++)
    {
       if(mat[r][r]!=0)
       {
           for(int c=0;c<R;c++)
            if(c!=r)
           {
               int mult=ZpMul(mat[c][r],InvMod(mat[r][r],module),module);
               for(int i = 0; i < C; i++)
               {
                   mat[c][i] =ZpSum(mat[c][i],(-1)*ZpMul(mult,mat[r][i],module),module);
               }

           }

        }
        //
        for (int i=0;i<R;i++)
        {
            for(int j=0;j<C;j++)
            {
                std::cout<<mat[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        //

       }
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
  x=X_coordinate%Mod_base;
  y=Y_coordinate%Mod_base;
  z=Z_coordinate%Mod_base;
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

ZpVec ZpVec::operator*(int c)
{
    return ZpVec(ZpMul(x,c,p),ZpMul(y,c,p),ZpMul(z,c,p),p);
}

std::ostream& operator<<(std::ostream& os,const ZpVec& Vec)
{
    os<<'('<<Vec.x<<','<<Vec.y<<','<<Vec.z<<')'<<" mod "<<Vec.p<<std::endl;
    return os;
}

int ZpVec::ScalarMul(const ZpVec& left, const ZpVec& right)
{
    return (ZpMul(left.x,right.x,left.p)+ZpMul(left.y,right.y,left.p)+ZpMul(left.z,right.z,left.p))%left.p;
}

double ZpVec::VecModule()
{
    return sqrt(x*x+y*y+z*z);
}


//-----------------------------------------------------------------------------------------------------------------------
ZpPoint::ZpPoint()
{
    x=0;
    y=0;
    z=0;
    p=0;
}

ZpPoint::ZpPoint(int a,int b,int c,int m)
{
    x=a;
    y=b;
    z=c;
    p=m;
}

ZpPoint operator+(const ZpPoint& left, const ZpPoint& right)
{
    return ZpPoint(ZpSum(left.x,right.x,left.p),ZpSum(left.y,right.y,left.p),ZpSum(left.z,right.z,left.p),left.p);
}


ZpPoint ZpPoint::operator*(int c)
{
    return ZpPoint(ZpMul(x,c,p),ZpMul(y,c,p),ZpMul(z,c,p),p);
}

 ZpPoint operator-(const ZpPoint& left, const ZpPoint& right)
{
    return ZpPoint(ZpSum(left.x,-1*right.x,left.p),ZpSum(left.y,-1*right.y,left.p),ZpSum(left.z,-1*right.z,left.p),left.p);
}

std::ostream& operator<<(std::ostream& os,const ZpPoint& P)
{
    os<<'('<<P.x<<','<<P.y<<','<<P.z<<')'<<" mod "<<P.p<<std::endl;
    return os;
}




