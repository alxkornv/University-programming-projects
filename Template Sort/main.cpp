#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#define less(x,y)  (x < y)              // функция сравнения элементов
#define swap(x,y)  {int t=x; x=y; y=t;} // процедура перестановки элементов
#define Tswap(x,y) {Type t=x;x=y;y=t;}
#define variant 1
using namespace std;


class BadInput : public std::exception {
	std::string reason;

public:
	BadInput() :
		reason("Bad input")
	{}

	BadInput(std::string _reason) :
		reason(_reason)
	{}

	const char* what() const throw() {
		return reason.c_str();
	}
};
//4 масти: spades, hearts, diamonds, clubs
//52 карты: 2<3<4<5<6<7<8<9<10<11<12<13<14
class Playing_card
{

public:
	int value;
	string suit; //spades, hearts, diamonds, clubs

	Playing_card() : value(2), suit("hearts") {}
	Playing_card(int a, string str)
	{
	   if(a>1 && a<15)
       {
           value = a;
       }
       else if(a>14)
       {
           value = a%14;
       }
       else
       {
           throw BadInput("Inappropriate value input");
       }
        suit = str;

	}
    bool operator < (const Playing_card& card)
    {
        int this_suit_val, card_suit_val;

        #if variant
        if(suit == "hearts") this_suit_val = 4;
        if(suit == "diamonds") this_suit_val = 3;
        if(suit == "clubs") this_suit_val = 2;
        if(suit == "spades") this_suit_val = 1;

        if(card.suit == "hearts") card_suit_val = 4;
        if(card.suit == "diamonds") card_suit_val = 3;
        if(card.suit == "clubs") card_suit_val = 2;
        if(card.suit == "spades") card_suit_val = 1;

        #elif
        if(suit == "hearts") this_suit_val = 2;
        if(suit == "diamonds") this_suit_val = 1;
        if(suit == "clubs") this_suit_val = 1;
        if(suit == "spades") this_suit_val = 1;


        if(card.suit == "hearts") card_suit_val = 2;
        if(card.suit == "diamonds") card_suit_val = 1;
        if(card.suit == "clubs") card_suit_val = 1;
        if(card.suit == "spades") card_suit_val = 1;
        #endif // variant

        if(this_suit_val != card_suit_val)
        {
            return this_suit_val < card_suit_val;
        }
        else
        {
            return this->value < card.value;
        }

    }

    Playing_card& operator= (const Playing_card& card)
    {
        value = card.value;
        suit = card.suit;
    }

	void print() {
		cout << "My suit is " << suit << " and my value is " << value << endl;
	}

	~Playing_card() {}

};

template <class Type>
void t_sort_bubble(Type a[], int max)
{
    for (int i = 0; i<max; i++)
		for (int j = max - 1; j>i; j--)
			if (less(a[j], a[j - 1]))
            {
                Tswap(a[j],a[j-1]);
            }
}

template <class Type>
void t_sort_choose(Type a[], int max)      // сортировка выбором методом вставки
{
	for (int i = 0; i<max; i++)
	{
		int k = i;
		for (int j = i + 1; j<max; j++)
			if (less(a[j], a[k]))
				k = j;
		if (i != k)
			Tswap(a[i], a[k]);
	}
}

template <class Type>
void t_sort_shell(Type a[], int max)               // сортировка Шелла
{
	for (int gap = max / 2; gap>0; gap /= 2)        // выбор интервала
		for (int i = gap; i<max; i++)               // проход массива
													// сравнение пар, отстоящих на gap друг от друга
			for (int j = i - gap; j >= 0 && less(a[j + gap], a[j]); j -= gap)
				Tswap(a[j], a[j + gap]);
}

template <class Type>
void t_sort_hoare(Type a[], int l, int r)   // сортировка Хоара
{
	int i = l, j = r, step = -1, condition = 1;
	if (l >= r) return;                   // сортировать нечего

	do {                         // сортируем с левой границы до правой
		if (condition == less(a[j], a[i]))
		{
			Tswap(a[i], a[j]);             // перестановка чисел
			swap(i, j);                   // обмен местами индексов
			step = -step;                 // теперь - в другую сторону
			condition = !condition;       // обмен условия на противоположное
		}
		j += step;                        // передвинем индекс
	} while (j != i);                     // пока индексы не сойдутся
	t_sort_hoare(a, l, i - 1);               // левое подмножество
	t_sort_hoare(a, i + 1, r);               // правое
}


template <class Type>
void t_sort_quick(Type a[], int l, int r) // QuickSort
{
	int i = l, j = r;
	Type x = a[(l + r) / 2];
	do {
		while (less(a[i], x)) i++;
		while (less(x, a[j])) j--;
		if (i <= j) {
			Tswap(a[i], a[j]);
			i++;
			j--;
		};
	} while (i<j);
	if (l<j) t_sort_quick(a, l, j);
	if (i<r) t_sort_quick(a, i, r);
}

int main()
{
    int n;

	ifstream in("in.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	cin >> n;
	Playing_card *b;
	b = new Playing_card[n];

	for (int i = 0; i < n; i++) { cin >> b[i].value; cin >> b[i].suit;}
	cin.rdbuf(cinbuf);
	in.close();


	//t_sort_bubble(b,n);
    //t_sort_choose(b,n);
    //t_sort_shell(b,n);
    //t_sort_hoare(b,0,n);
    t_sort_quick(b,0,n);

	ofstream out("out.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());
	cout << n << endl;
	for (int i = 0; i < n; i++) b[i].print();

	cout.rdbuf(coutbuf);
	out.close();

    return 0;
}
