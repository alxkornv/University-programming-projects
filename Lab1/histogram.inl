
//-----------------------------------------------------------------
// Функция InitHistogram инициализирует данные гистограммы
void inline InitHistogram(Histogram &historgam){
	historgam.nBarsSize = 0;
	historgam.BarNames = 0;//Всегда обнуляйте неинициализированные указатели
	historgam.Bars = 0;    //Всегда обнуляйте неинициализированные указатели
	historgam.chBlock = '#';
	historgam.nMaxBar = 0;
}

//-----------------------------------------------------------------
// Функция DesroyHistogram освобождает занятую память
void inline DestroyHistogram(Histogram &historgam){
	if(historgam.nBarsSize){
		delete[] historgam.BarNames;
		historgam.BarNames = 0; //Всегда обнуляйте указатели после освобождения памяти
		delete[] historgam.Bars;
		historgam.Bars = 0; //Всегда обнуляйте указатели после освобождения памяти
	}
	historgam.nMaxBar = 0;

}