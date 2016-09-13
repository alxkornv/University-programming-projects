#include "histogram.h"
#include <string>
#include <utility>
#include <vector>
int lab1task(std::string,std::vector<std::pair<char,int>> &MyVec);

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
    std::string str="AojoAiojOytliIiuhgIJHUHtU";
    //std::cout<<"Enter string >> ";
    //std::cin>>str;
    std::cout<<str<<std::endl;


    std::vector<std::pair<char,int>> MyVec;
    lab1task(str,MyVec);


	InitHistogram(myBarChart);
    for(int i=0;i<MyVec.size();i++)
    {
        BarName=MyVec.at(i).first;
        for(int j=0;j<MyVec.at(i).second;j++)
        {
            AddBlock(myBarChart,BarName.c_str());
        }
    }
	PrintHistogram(myBarChart);
	DestroyHistogram(myBarChart);

	return 0;
}

int lab1task (std::string str,std::vector<std::pair<char,int>> &MyVec)
{
    size_t found=std::string::npos;
    char temp;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            MyVec.push_back(std::make_pair(str[i],1));
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


    return 0;
}
