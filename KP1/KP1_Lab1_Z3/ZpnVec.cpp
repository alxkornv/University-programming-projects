#include "ZPNvec.h"
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
            for(int j=0;j<(*vec.begin()).size();++j)
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
ZpnVec::ZpnVec()
{
    dim=0;
    md=0;
}
ZpnVec::ZpnVec(std::vector<int> inpvec,int n,int module)
{
    dim=n;
    md=module;
    vec=inpvec;
}
ZpnVec::ZpnVec(const ZpnVec& v)
{
    dim=v.dim;
    md=v.md;
    vec=v.vec;

}

ZpnVec& ZpnVec::operator=(const ZpnVec& v)
{
    dim=v.dim;
    md=v.md;
    vec=v.vec;
    return *this;
}
 bool LinearDependence(std::vector<ZpnVec>& v, int md)
    {
        std::vector<std::vector<int>> mat;
        int r=v.size();

        for(int i=0;i<r;++i)
        {
            //mat.push_back(std::vector<int>);
            std::vector<int> tmp;
            for(int j=0;j<(*v.begin()).vec.size();++j)
            {
                tmp.push_back(v[i].vec[j]);
                //mat[i].push_back(v[i].vec[j]);
            }
            mat.push_back(tmp);
            tmp.clear();

        }
       // PrintMatrix(mat);
        std::cout<<std::endl;
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
                        /*std::cout<<std::endl;
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
                    if(mat[i][row])
                    {
                        swapLines(mat, row, i);
                      /*  std::cout<<std::endl;
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
                }
                row--;
            }
        }
       // std::cout << rk << std::endl;
       int newrk=0;
          for(int i=0;i<r;++i)
        {

            for(int j=0;j<(*v.begin()).vec.size();++j)
            {

                if(mat[i][j]!=0)
                {

                    newrk++;
                    break;
                }

            }

        }
        if(newrk<std::min(r, (int)mat[0].size()))
        {
            std::cout<<'0'<<std::endl;
        }
        else
        {
            std::cout<<'1'<<std::endl;
        }
        std::cout << newrk << std::endl;
        for(int i=0;i<r;++i)
        {
            bool flag=0;
            for(int j=0;j<(*v.begin()).vec.size();++j)
            {

                if(mat[i][j]!=0)
                {
                    flag=1;
                    break;
                }

            }
            if(flag)
                {
                    for(int k=0;k<(*v.begin()).vec.size();++k)
                    {
                        std::cout<<mat[i][k]<<' ';
                    }
                    std::cout<<std::endl;
                }
        }
        if(v.size() == rk)
        {
            return false; //NE ZAVIS
        }
        else
        {
            return true; //ZAVIS
        }

    }
