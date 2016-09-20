#include "histogram.h"

void lab1task(std::string,std::vector<std::pair<std::string,int>> &MyVec);//Ôóíêöèÿ ñáîðà äàííûõ äëÿ ãèñòîãðàììû
void MyVecSort(std::vector<std::pair<std::string,int>> &MyVec,bool bAscending=true);//Ôóíêöèÿ ñîðòèðîâêè äàííûõ
//Âñïîìîãàòåëüíûå ôóíêöèè äëÿ ðàáîòû std::sort
bool MyAscCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2);
bool MyDesCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2);
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
    std::string str;
    std::cout<<"Enter string >> ";
    std::cin>>str;
    std::cout<<std::endl;
    std::vector<std::pair<std::string,int>> MyVec;//Äëÿ óäîáñòâà õðàíåíèÿ è ñîðòèðîâêè äàíííûõ èñïîëüçóåòñÿ âåêòîð ïàð
    //Êàæäàÿ ïàðà ñîñòîèò èç ñòðîêè è öåëîãî ÷èñëà - íàçâàíèÿ î÷åðåäíîãî ñòîëáöà è ðàçìåðà ñòîëáöà ñîîòâåòñâåííî

    lab1task(str,MyVec);

    MyVecSort(MyVec,false);

	InitHistogram(myBarChart);

	//Çàïîíåíèå ïîëåé ñòðóêòóðû ãìñòîãðàììåðà
    for(unsigned int i=0;i<MyVec.size();i++)
    {
        for(int j=0;j<MyVec.at(i).second;j++)
        {
            AddBlock(myBarChart,MyVec.at(i).first.c_str());
        }
    }
    AddBlock(myBarChart,"Left");
    AddBlock(myBarChart,"Alignment");

	PrintHistogram(myBarChart);
	DestroyHistogram(myBarChart);

	return 0;
}

void lab1task (std::string str,std::vector<std::pair<std::string,int>> &MyVec)
{
    size_t found=std::string::npos;
    char temp;
    std::string t;
    for(unsigned int i=0;i<str.length();)//Âûïîëíÿåòñÿ ïðîõîä ïî âñåé ââåäåííîé ñòðîêå
    {
        if(str[i]>='A' && str[i]<='Z')//Åñëè î÷åðåäíîé îáðàáàòûâàåìûé ñèìâîë ñòðîêè - çàãëàâíàÿ ëàòèíñêàÿ áóêâà
        {
            t=str[i];
            MyVec.push_back(std::make_pair(t,1));//Òî â âåêòîð äîáàâëÿåòñÿ î÷åðåäíàÿ ïàðà
            //Â ïåðâîå ïîëå ïàðû çàíîñèòñÿ ñàìà áóêâà, âî âòîðîå - 1
            temp=str[i];
            //Äàëåå, ÷òîáû â äàëüíåéøåì ïðîõîäå ïî ñòðîêå íå ïðîâåðÿòü, áûëà ëè óæå çàïèñàíà íàéäåííàÿ áóêâà â âåêòîð èëè íåò, áûë ðåàëèçîâàí ñëåäóþùèé àëãîðèòì
            str.erase(str.begin()+i);//Íàéäåííàÿ áóêâà óäàëÿåòñÿ èç ñòðîêè

            //Äàëåå â ñòðîêå ïðîèñõîäèò ïîèñê âñåõ òàêèõ æå áóêâ

            do
            {
                found=str.find(temp);
                if(found!=std::string::npos)//Åñëè òàêèå áóêâû íàõîäèñÿ
                {
                    MyVec.back().second++;//Òî ñ÷åò÷èê â ïàðå óâåëè÷èâàåòñÿ
                    str.erase(str.begin()+found);//È íàéäåííàÿ áóêâà óäàëÿåòñÿ
                }
            }
            while(found!=std::string::npos);
        }
        else{i++;}

    }

    for(unsigned int i=0;i<MyVec.size();i++)
    {
        std::cout<<MyVec.at(i).first<<' '<<MyVec.at(i).second<<std::endl;
    }
    std::cout<<std::endl;
}
bool MyAscCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2)
{
    return p1.second<p2.second;
}

bool MyDesCompare(std::pair<std::string,int> p1, std::pair<std::string,int> p2)
{
    return p1.second>p2.second;
}

void MyVecSort(std::vector<std::pair<std::string,int>> &MyVec,bool bAscending)
{
    //äëÿ ñîðòèðîâêè äàííûõ èñïîëüçóåòñÿ ôóíêöèÿ std::sort
    if(!bAscending)
    std::sort(MyVec.begin(),MyVec.end(),MyDesCompare);
        else
    std::sort(MyVec.begin(),MyVec.end(),MyAscCompare);
}
