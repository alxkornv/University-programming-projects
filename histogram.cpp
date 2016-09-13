#include "histogram.h"
#include <iostream>
#include <iomanip>

using namespace std;

///////////////////////////////////////////////////////////////////
// Вспомогательные функции
void AddBar(Histogram &historgam, const char *strName);
bool AppendBar(Histogram &historgam, const char *strName);

///////////////////////////////////////////////////////////////////
// реализация функций из файла histogram.h


//-----------------------------------------------------------------
// Функция AddBlock увеличивает значение столбца strName гистограмы historgam на 1.
// Если столбца с таким именем не существует, он создается.
void AddBlock(Histogram &historgam, const char *strName){
	if(!AppendBar(historgam, strName)){
		AddBar(historgam, strName);
	}
}

//-----------------------------------------------------------------
// Функция PrintHistogram выводит гистограму на экран.
void PrintHistogram(const Histogram &historgam){
	for(int i=0; i<historgam.nBarsSize; i++){
		cout << historgam.BarNames[i] << '|';
		//cout.setf
		cout << setfill(historgam.chBlock) << setw(10*historgam.Bars[i]/historgam.nMaxBar) << "" << /*ends <<*/ endl;
	}
}

///////////////////////////////////////////////////////////////////
// реализация вспомогательных функций

//-----------------------------------------------------------------
// Функция AppendBar увеличивает значение столбца strName гистограмы historgam на 1.
bool AppendBar(Histogram &historgam, const char *strName){
	for(int i=0; i<historgam.nBarsSize; i++){
		if(strcmp(historgam.BarNames[i], strName)==0){
			historgam.nMaxBar = max(historgam.nMaxBar, ++historgam.Bars[i]);
			return true;
		}
	}
	return false;
}

// Функция AddBar создает в гистограме historgam новый столбец с именем strName.
//-----------------------------------------------------------------
void AddBar(Histogram &historgam, const char *strName){
	char **newNames = new char *[historgam.nBarsSize+1];
	int   *newBars  = new int[historgam.nBarsSize+1];
	if(historgam.nBarsSize > 0){
		for(int i=0; i<historgam.nBarsSize; i++){
			newNames[i] = historgam.BarNames[i];
			newBars[i] = historgam.Bars[i];
		}
		delete[] historgam.BarNames;
		delete[] historgam.Bars;
	}

	newNames[historgam.nBarsSize] = new char[strlen(strName)+1];
	strcpy(newNames[historgam.nBarsSize], strName);
	newBars[historgam.nBarsSize] = 1;

	historgam.nBarsSize++;
	historgam.BarNames = newNames;
	historgam.Bars = newBars;
}

