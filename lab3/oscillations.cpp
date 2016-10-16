#include "oscillations.h"
std::ostream& operator<<(std::ostream& os,const Oscil& osc)
{
    if(osc.phase>=0)
    {
     os<<"x(t)="<<osc.amptd<<"sin("<<osc.freq<<"t+"<<osc.phase<<")"<<std::endl;
    }
    else
    {
        os<<"x(t)="<<osc.amptd<<"sin("<<osc.freq<<"t"<<osc.phase<<")"<<std::endl;
    }
    return os;
}


/*Oscil Oscil::operator=(Ocsil osc)
{
    amptd=osc.amptd;
    freq=osc.freq;
    phase=osc.phase;
    return *this;
}*/
void Oscil::init(double a, double f, double p)
{
    amptd=a;
    freq=f;
    phase=p;
}
