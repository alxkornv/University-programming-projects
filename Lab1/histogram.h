#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
//Структура для описания гисторгаммы
typedef struct{
	char **BarNames;
	int *Bars;
	int nBarsSize;
	char chBlock;
	int nMaxBar;
} Histogram;


//Функции для работы с гисторгаммой
void inline InitHistogram(Histogram &historgam);
void inline DestroyHistogram(Histogram &historgam);
void PrintHistogram(const Histogram &historgam);
void AddBlock(Histogram &historgam, const char *strName);
void SortByVal (Histogram &historgam, bool bAscending = true);
#include "histogram.inl"
