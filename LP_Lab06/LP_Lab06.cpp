// LP_Lab06.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned char year;
struct  Date
{
	day dd;
	month mm;
	year yyyy;
};

bool operator==(Date d1, Date d2) { //перегрузка оператора 
	if ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd == d2.dd))
		return true;
	else return false;
}

bool operator>(Date d1, Date d2) {
	if ((d1.yyyy > d2.yyyy)   ||   ((d1.yyyy==d2.yyyy)&&(d1.mm > d2.mm))   ||   ((d1.yyyy==d2.yyyy)&&(d1.mm==d2.mm)&&(d1.dd > d2.dd)))
		return true;
	else return false;
}

bool operator<(Date d1, Date d2) {
	if ((d1.yyyy < d2.yyyy)   ||   ((d1.yyyy==d2.yyyy)&&(d1.mm < d2.mm))   ||   ((d1.yyyy==d2.yyyy)&&(d1.mm==d2.mm)&&(d1.dd < d2.dd)))
		return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");

	Date date1 = { 7,1,1980 };
	Date date2 = { 7,2,1993 };
	Date date3 = { 7,1,1980 };

	if (date1 < date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 > date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 == date2)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;

	if (date1 == date3)
		cout << "истина" << endl;
	else
		cout << "ложь" << endl;
	system("pause");
	return 0;
}


/*
//ЗАДАНИЕ 2
//Разработайте две операции для данных указ. типа, реализовав каждую из них в виде функции
//комплексное число
//z=x+iy (x-действ.ч, y-мним.ч.)

struct Complex {
int x; //действ.
int y;	//мним.
};

int operator +(Complex z1, Complex z2) {
if (z1.y + z2.y > 0) {
cout << "\nРезультат сложения: \n" << z1.x + z2.x << " + " << z1.y + z2.y << "i\n";
}
if (z1.y + z2.y < 0) {					///склад.дейсв. части		модуль суммы
cout << "\nРезультат сложения: \n" << z1.x + z2.x << " - " << -(z1.y + z2.y) << "i\n";
}
return(1);
}
int operator -(Complex z1, Complex z2) {
if (z1.y - z2.y < 0) {
cout << "\nРезультат вычитания: \n" << z1.x - z2.x << " - " << z1.y - z2.y << "i\n\n";
}
if (z1.y - z2.y > 0) {
cout << "\nРезультат вычитания: \n" << z1.x - z2.x << " + " << z1.y - z2.y << "i\n\n";
}
return(1);
}
int main()
{
setlocale(LC_ALL, "Rus");
Complex z1 = { 5,9 };
Complex z2 = { 2,3 };
z1 + z2;
z1 - z2;
system("pause");
return 0;
}
*/