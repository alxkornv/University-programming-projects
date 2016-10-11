#include "figure.h"
#include <array>

using namespace std;

#include <iostream>

void MultiplyMatrix() {

    int a1,a2,b1,b2;
    do
    {
        cout<<"Enter number of raws (a1) and number of columns (a2) in matrix A"<<endl<<"a1 = ";
        cin>>a1;
        cout<<endl<<"a2 = ";
        cin>>a2;
        cout<<"Enter number of raws (b1) and number of columns (b2) in matrix B"<<endl<<"b1 = ";
        cin>>b1;
        cout<<endl<<"b2 = ";
        cin>>b2;
        if(a2!=b1)
        {
            cout<<"Matrices can not be multiplied";
        }
    }
    while(a2!=b1);

    int **aMatrix=new int* [a1];
    for (int i=0;i<a1;i++)
    {
        aMatrix[i]=new int [a2];
    }


    int **bMatrix=new int* [b1];
    for (int i=0;i<b1;i++)
    {
        bMatrix[i]=new int [b2];
    }


    int **product=new int* [a1];
    for (int i=0;i<b1;i++)
    {
        product[i]=new int [b2];
    }
    int num=1;

    for(int i=0;i<a1;i++)
    {
        for(int j=0;j<a2;j++)
        {
            aMatrix[i][j]=num;
            num++;
        }
    }
    num=2;

    for(int i=0;i<b1;i++)
    {
        for(int j=0;j<b2;j++)
        {
            bMatrix[i][j]=num;
            num++;
        }
    }
    cout<<"Matrix A"<<endl;
    for(int i=0;i<a1;i++)
    {
        for(int j=0;j<a2;j++)
        {
            cout<<aMatrix[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Matrix B"<<endl;
    for(int i=0;i<b1;i++)
    {
        for(int j=0;j<b2;j++)
        {
            cout<<bMatrix[i][j]<<' ';
        }
        cout<<endl;
    }






    for (int row = 0; row < a1; row++) {
        for (int col = 0; col < b2; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < 2; inner++) {
                product[row][col] += aMatrix[row][inner] * bMatrix[inner][col];
            }
            std::cout << product[row][col] << "  ";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < a1; i++) {
        delete [] aMatrix[i];
    }
    delete [] aMatrix;

    for (int i = 0; i < b1; i++) {
        delete [] bMatrix[i];
    }
    delete [] bMatrix;

}
int main()
{
    //MultiplyMatrix();
    circle c1;
    c1.create_figure();
    cout<<c1;
    return 0;
}
