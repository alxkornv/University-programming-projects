#include "ZpVector.h"
using namespace std;

int main()
{
    ZpVector v1(1,2,3,7);
    ZpVector v2(6,5,4,7);
    ZpVector v3(5,5,5,7);

    std::vector<ZpVector> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    if(LinearDependence(v, 7))
        std::cout << "DEP";
    else
        std::cout << "NOT DEP";
    return 0;
}
