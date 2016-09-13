#include "histogram.h"
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
void lab1task(std::string,std::vector<std::pair<std::string,int>> &MyVec);
void MyVecSort(std::vector<std::pair<std::string,int>> &MyVec);
bool MyCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2);
int main()
{
	const char * const strProgramName = "Histogramer 1.0";
    std::string BarName;
	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << "* " << strProgramName << " *" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl << std::endl;

	Histogram myBarChart;
    std::string str="HHHoPLL";
    //std::cout<<"Enter string >> ";
    //std::cin>>str;
    std::cout<<str<<std::endl;


    std::vector<std::pair<std::string,int>> MyVec;
    lab1task(str,MyVec);

    MyVecSort(MyVec);
	InitHistogram(myBarChart);
    for(int i=0;i<MyVec.size();i++)
    {

        for(int j=0;j<MyVec.at(i).second;j++)
        {
            AddBlock(myBarChart,MyVec.at(i).first.c_str());
        }
    }
	PrintHistogram(myBarChart);
	DestroyHistogram(myBarChart);

	return 0;
}

void lab1task (std::string str,std::vector<std::pair<std::string,int>> &MyVec)
{
    size_t found=std::string::npos;
    char temp;
    std::string t;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            t=str[i];
            MyVec.push_back(std::make_pair(t,1));
            temp=str[i];
            str.erase(str.begin()+i);
            do
            {
                found=str.find(temp);
                if(found!=std::string::npos)
                {
                    MyVec.back().second++;
                    str.erase(str.begin()+found);

                }

            }
            while(found!=std::string::npos);
        }
    }

    for(int i=0;i<MyVec.size();i++)
    {
        std::cout<<"pair "<<i+1<<' '<<MyVec.at(i).first<<' '<<MyVec.at(i).second<<std::endl;
    }



}
bool MyCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2)
{
    return p1.second<p2.second;
}
void MyVecSort(std::vector<std::pair<std::string,int>> &MyVec)
{
    std::sort(MyVec.begin(),MyVec.end(),MyCompare);
}
