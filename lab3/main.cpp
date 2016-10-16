#include "figure.h"
#include "oscillations.h"
#include <iostream>

int main()
{

    circle c1;
    c1.create_figure();
    std::cout<<c1;
    c1.move_figure(1,2);
    std::cout<<c1;
    c1.rotate_figure(3.14);
    std::cout<<c1;
    c1.create_figure();
    c1.move_n_rotate(1,2,3.14);
    std::cout<<c1;

    triangle tr2;
    tr2.create_figure();
    std::cout<<tr2;

    rectangle rect1;
    rect1.create_figure();
    std::cout<<rect1;

    Oscil a,b,c;
    a.init(1,2,3);
    b.init(4,2,6);
    std::cout<<"A: "<<a<<std::endl;
    std::cout<<"B: "<<b<<std::endl;
    std::cout<<"C: "<<c<<std::endl;
    c=a+b;
    std::cout<<c;
    return 0;
}
