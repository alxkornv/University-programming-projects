#ifndef ZPVECTOR_H_INCLUDED
#define ZPVECTOR_H_INCLUDED
#include <iostream>
#include <cmath>
#include <vector>

//line1 <==> line2
void swapLines(std::vector <std::vector<int>>& vec, int line1, int line2)
{

    vec[line1].swap(vec[line2]);
}
void swapCols(std::vector <std::vector<int>>& vec, int col1, int col2)
{

    for(int i = 0; i < vec.size(); ++i)
    {
        int tmpNum;
        tmpNum = vec[i][col1];
        vec[i][col1] = vec[i][col2];
        vec[i][col2] = tmpNum;

    }


}
void PrintMatrix(std::vector <std::vector<int>>& vec)
{
    for(int i=0;i<vec.size();++i)
        {
            for(int j=0;j<3;++j)
            {
                std::cout<<vec[i][j]<<' ';
            }
            std::cout<<std::endl;
        }
}
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

class ZpPoint;
class ZpVector;

class ZpPoint
{
public:
const int dim=3;
int m;
std::vector<int> Point{std::vector<int>(dim)};


ZpPoint()
{
    m=1;
}
ZpPoint(int x, int y, int z)
{
    Point[0]=x;
    Point[1]=y;
    Point[2]=z;
}
ZpPoint(const ZpPoint& p)
{
        Point[0]=p.Point[0];
        Point[1]=p.Point[1];
        Point[2]=p.Point[2];
}
ZpPoint operator+(const ZpPoint& p) const
{
    return ZpPoint(ZpSum(Point[0],p.Point[0],m),ZpSum(Point[1],p.Point[1],m),ZpSum(Point[2],p.Point[2],m));
}

ZpPoint operator*(int c)
{
    return ZpPoint(ZpMul(Point[0],c,m),ZpMul(Point[1],c,m),ZpMul(Point[2],c,m));
}

};

inline ZpPoint operator*(int c, const ZpPoint& p)
{
	return ZpPoint(ZpMul(c,p.Point[0],p.m), ZpMul(c,p.Point[1],p.m),ZpMul(c,p.Point[2],p.m));
}


class ZpVector
{
public:
    const int dim=3;
    int m;
    std::vector<int> vec{std::vector<int>(dim)};
    ZpVector()
    {
       m=1;
    }
    ZpVector(const int& x,const int& y,const int& z,const int& module)
    {
        vec[0]=x;
        vec[1]=y;
        vec[2]=z;
        m=module;
    }
    ZpVector(const ZpVector& v)
    {
        vec[0]=v.vec[0];
        vec[1]=v.vec[1];
        vec[2]=v.vec[2];
    }
    ZpVector operator+(const ZpVector& v) const
    {
        return ZpVector(ZpSum(vec[0],v.vec[0],m),ZpSum(vec[1],v.vec[1],m),ZpSum(vec[2],v.vec[2],m),m);
    }

    ZpVector operator-(const ZpVector& v) const
    {
        return ZpVector(ZpSum(vec[0],(-1)*v.vec[0],m),ZpSum(vec[1],(-1)*v.vec[1],m),ZpSum(vec[2],(-1)*v.vec[2],m),m);
    }
    ZpVector operator*(const int c)
    {
        return ZpVector(ZpMul(c,vec[0],m),ZpMul(c,vec[1],m),ZpMul(c,vec[2],m),m);
    }
    ZpVector& operator+(const ZpVector& v)
    {
        vec[0]=v.vec[0];
        vec[1]=v.vec[1];
        vec[2]=v.vec[2];
        return *this;
    }
    friend int ScalarProduct(const ZpVector& u, const ZpVector& v)
    {
        int d1,d2,d3;
        d1=ZpMul(u.vec[0],v.vec[0],u.m);
        d2=ZpMul(u.vec[1],v.vec[1],u.m);
        d3=ZpMul(u.vec[2],v.vec[2],u.m);
        int res=ZpSum(d1,ZpSum(d2,d3,u.m),u.m);
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const ZpVector& v)
	{
		os<<'('<<v.vec[0]<<','<<v.vec[1]<<','<<v.vec[2]<<')';
		return os;
	}

    friend bool LinearDependence(std::vector<ZpVector>& v, int md)
    {
        std::vector<std::vector<int>> mat; //sooqa
        int r=v.size();

        for(int i=0;i<r;++i)
        {
            //mat.push_back(std::vector<int>);
            std::vector<int> tmp;
            for(int j=0;j<3;++j)
            {
                tmp.push_back(v[i].vec[j]);
                //mat[i].push_back(v[i].vec[j]);
            }
            mat.push_back(tmp);
            tmp.clear();
        }
        PrintMatrix(mat);
        int rk = std::min(r, (int)mat[0].size());
        for(int row = 0; row < rk; ++row)
        {
            if(mat[row][row])
            {
                // go down the column
                for(int col = 0; col < mat.size(); ++col)
                {
                    if(col != row)
                    {
                        int mult = ZpMul(mat[col][row], InvMod(mat[row][row], md), md);
                        for(int i = 0; i < mat[0].size(); ++i)
                        {
                            mat[col][i] = ZpSum(mat[col][i], (-1) * ZpMul(mat[row][i], mult, md), md);
                        }
                        std::cout<<std::endl;
                        PrintMatrix(mat);
                        std::cout<<std::endl;
                    }

                }

            }
            else
            {
                bool reduce = true;
                for(int i = row + 1; i < mat.size(); ++i)
                {
                    if(mat[i][row])
                    {
                        swapLines(mat, row, i);
                        std::cout<<std::endl;
                        PrintMatrix(mat);
                        std::cout<<std::endl;
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
                }
                row--;
            }
        }
        std::cout << rk << std::endl;
        if(v.size() == rk)
        {
            return false; //NE ZAVIS
        }
        else
        {
            return true; //ZAVIS
        }

    }

};

inline ZpVector operator*(int c, const ZpVector& v)
{
	return ZpVector(ZpMul(c,v.vec[0],v.m),ZpMul(c,v.vec[1],v.m),ZpMul(c,v.vec[2],v.m),v.m);
}

#endif // ZPVECTOR_H_INCLUDED
