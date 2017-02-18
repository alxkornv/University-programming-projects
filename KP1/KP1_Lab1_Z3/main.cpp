#include <iostream>
#include "ZPNvec.h"
using namespace std;

void LinDep()
{
    int n,p,m;
    int temp;
    std::vector<int> v ;
    std::vector<ZpnVec> a;
    std::cin>>p>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cin>>temp;
            v.push_back(temp);
        }
        a.push_back(ZpnVec(v,n,p));
        v.clear();
    }
    LinearDependence(a,p);

}

int main()
{
    /*std::vector<int> v ;
    v={1,1,1,1,1};
    ZpnVec v1(v,5,13);
    v={1,12,1,1,1};
    ZpnVec v2 (v,5,13);
    v={1,0,1,1,2};
    ZpnVec v3(v,5,13);
    std::vector<ZpnVec> a;
    a.push_back(v1);
    a.push_back(v2);
    a.push_back(v3);
    LinearDependence(a,13);*/
    LinDep();

    return 0;
}
