#include <iostream>
#include <locale>
#include <string>
#include <conio.h>
using std::cout;
using std::cin;
using std::string;
using std::getline;

int conv(char);
int main()
{
	int num=0, t_num1, t_num2;
	string st;
	bool flag=false;
	char c;
	cout<<"Enter roman number \n";
	getline(cin,st);
	for(int i=0;i<st.size()-1;i++)
	{
		c=toupper(st[i]);
		t_num1=conv(c);
		c=toupper(st[i+1]);
		t_num2=conv(c);
		if(t_num1>=t_num2)
		{
			num+=t_num1;
		}
		else
		{
			num+=(t_num2-t_num1);
			i++;//если выполнилось это условие, то текущее число, добавляемое к общей сумме, состояло из двух цифр, и послнднее число из этих двух не нужно сравнивать со следующим, чтобы избежать ошибки
		}
	}
	if(t_num1>t_num2)
		num+=t_num2;

	cout<<"Decimal arabic number: "<<num;

	_getch();
	return 0;
}

int conv(char c)
{
	bool flag=false;
	int num;
	switch (c)
	{
		case 'I': {num=1; flag=true; break;}
		case 'V': {num=5; flag=true; break;}
		case 'X': {num=10; flag=true; break;}
		case 'L': {num=50; flag=true; break;}
		case 'C': {num=100; flag=true; break;}
		case 'D': {num=500; flag=true; break;}
		case 'M': {num=1000; flag=true; break;}
	}

	if(!flag)
		{
			cout<<"Incorrect number \n";
			_getch();
			return 1;
		}
	return num;
}