#include "histogram.h"
#include <iostream>
#include <iomanip>

 
int main(){
	const char * const strProgramName = "Histogramer 1.0";

	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << "* " << strProgramName << " *" << std::endl;
	std::cout << '*' << std::setfill(' ') << std::setw(strlen(strProgramName)+3) << '*' << std::endl;
	std::cout << std::setfill('*') << std::setw(strlen(strProgramName)+4) << "" << std::endl << std::endl;

	Histogram myBarChart;

	InitHistogram(myBarChart);
	AddBlock(myBarChart, "a");
	AddBlock(myBarChart, "a");
	AddBlock(myBarChart, "a");
	AddBlock(myBarChart, "b");
	AddBlock(myBarChart, "c");
	AddBlock(myBarChart, "a");
	AddBlock(myBarChart, "d");
	AddBlock(myBarChart, "e");
	AddBlock(myBarChart, "c");
	AddBlock(myBarChart, "z");
	AddBlock(myBarChart, "z");
	AddBlock(myBarChart, "z");
	AddBlock(myBarChart, "z");
	AddBlock(myBarChart, "z");
	AddBlock(myBarChart, "Y");
	AddBlock(myBarChart, "Y");



	PrintHistogram(myBarChart);

	DestroyHistogram(myBarChart);

	return 0;
}