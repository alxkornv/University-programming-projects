#ifndef OSCILLATIONS_H_INCLUDED
#define OSCILLATIONS_H_INCLUDED
#pragma once
#include <sstream>
#include <cmath>
#include <iostream>
class Oscil
{
public:
    Oscil(){freq=0.0;amptd=0.0;phase=0.0;};
    ~Oscil(){};
    void init(double,double,double);
    Oscil operator=(Oscil osc)
   {
    amptd=osc.amptd;
    freq=osc.freq;
    phase=osc.phase;
    return *this;
    }
    Oscil operator+(Oscil osc)
    {
        if(freq!=osc.freq)
        {
            std::cout<<"Oscillations have different frequences, they would be added as if they had equal frequences"<<std::endl;;

        }
        Oscil res;
        res.freq=freq;
        res.amptd=sqrt(pow(amptd,2)+pow(osc.amptd,2)+2*(amptd)*osc.amptd*cos(phase-osc.phase));
        res.phase=atan( ( amptd*sin(phase)+osc.amptd*sin(osc.phase) ) / ( amptd*cos(phase)+osc.amptd*cos(osc.phase) ) );
        return res;

    }

    friend std::ostream& operator<<(std::ostream& os,const Oscil& osc);

private:
    double freq;
    double amptd;
    double phase;
};


#endif // OSCILLATIONS_H_INCLUDED
