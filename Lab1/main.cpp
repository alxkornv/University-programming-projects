#include "histogram.h"

void lab1task(std::string,std::vector<std::pair<std::string,int>> &MyVec);//Функция сбора данных для гистограммы
void MyVecSort(std::vector<std::pair<std::string,int>> &MyVec,bool bAscending=true);//Функция сортировки данных
//Вспомогательные функции для работы std::sort
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
    std::vector<std::pair<std::string,int>> MyVec;//Для удобства хранения и сортировки даннных используется вектор пар
    //Каждая пара состоит из строки и целого числа - названия очередного столбца и размера столбца соответсвенно

    lab1task(str,MyVec);

    MyVecSort(MyVec,false);

	InitHistogram(myBarChart);

	//Запонение полей структуры гмстограммера
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
    for(unsigned int i=0;i<str.length();)//Выполняется проход по всей введенной строке
    {
        if(str[i]>='A' && str[i]<='Z')//Если очередной обрабатываемый символ строки - заглавная латинская буква
        {
            t=str[i];
            MyVec.push_back(std::make_pair(t,1));//То в вектор добавляется очередная пара
            //В первое поле пары заносится сама буква, во второе - 1
            temp=str[i];
            //Далее, чтобы в дальнейшем проходе по строке не проверять, была ли уже записана найденная буква в вектор или нет, был реализован следующий алгоритм
            str.erase(str.begin()+i);//Найденная буква удаляется из строки

            //Далее в строке происходит поиск всех таких же букв

            do
            {
                found=str.find(temp);
                if(found!=std::string::npos)//Если такие буквы находися
                {
                    MyVec.back().second++;//То счетчик в паре увеличивается
                    str.erase(str.begin()+found);//И найденная буква удаляется
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
    //для сортировки данных используется функция std::sort
    if(!bAscending)
    std::sort(MyVec.begin(),MyVec.end(),MyDesCompare);
        else
    std::sort(MyVec.begin(),MyVec.end(),MyAscCompare);
}
