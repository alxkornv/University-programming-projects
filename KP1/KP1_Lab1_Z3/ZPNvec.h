#ifndef ZPNVEC_H_INCLUDED
#define ZPNVEC_H_INCLUDED
#include <vector>
#include <iostream>



class ZpnVec
{
public:
    int dim;
    int md;
    std::vector<int> vec;

    ZpnVec();
    ZpnVec(std::vector<int>,int n,int module);
    ZpnVec(const ZpnVec&);
    ZpnVec& operator=(const ZpnVec&);
   // ZpnVec operator+(const ZpnVec& ) const;
    //ZpnVec operator-(const ZpnVec&) const;
    friend bool LinearDependence(std::vector<ZpnVec>& v, int md);

};

#endif // ZPNVEC_H_INCLUDED
