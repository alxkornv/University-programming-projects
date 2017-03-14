#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iterator>
#include <locale>
#include <exception>
int RandomNumber()
{
    return std::rand()%100;
}

std::vector<std::string> Split(std::string str)
{


    std::istringstream iss(str);
    std::vector<std::string> vec;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(vec));

    return vec;
}

std::string VecToStr(std::vector<std::string> vec, bool low=true)
{
    std::locale loc;
    std::string newstr;
    for(std::vector<std::string>::iterator it=vec.begin();it!=vec.end();++it)
    {
        newstr.append(*it);
    }
    if(low)
    {
        for(size_t i=0;i<newstr.size();++i)
        {
            newstr[i]=tolower(newstr[i],loc);
        }
    }

    return newstr;
}

bool IsPalindrome(std::string str)
{
    std::vector<std::string> myvec = Split(str);
    std::string tempstr = VecToStr(myvec,1);
    std::string newstr;
    newstr.resize(tempstr.size());
    std::reverse_copy(tempstr.begin(),tempstr.end(),newstr.begin());
    return (tempstr == newstr);
   
}

bool AllPalindrome(std::vector<std::string> vec)
{
    return std::all_of(vec.begin(),vec.end(),IsPalindrome);
}

std::vector<int> RandVec20()
{
    std::vector<int> myvec(20);
    std::vector<int>::iterator it;
    std::generate (myvec.begin(), myvec.end(), RandomNumber);
    for(it=myvec.begin();it!=myvec.end();++it)
    {
        std::cout<<*it<<' ';
    }

    std::cout<<std::endl;

    return myvec;
}

double MeanSpeed(std::string str)
{
    int dist=15951;
    int new_dist=std::stoi(str);
    if((new_dist>dist) && (IsPalindrome(str)))
    {
        return (new_dist-dist)*(1.0)/2.0;
    }
    else
    {
        throw std::invalid_argument("new distance is wrong or its not a palindrome");
    }

}

int main()
{

    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> newvec;
    newvec=RandVec20();

    std::vector<std::string> vec = {"Was it a cat I saw","15951"};
    std::cout<<AllPalindrome(vec);
    std::cout<<std::endl;
    std::cout<<MeanSpeed("26962");

    return 0;
}
