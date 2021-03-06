// LP_Lab09.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Varparm.h"
#include "Call.h"
#include <iostream>
#include <locale>
using namespace std;

int defaultparm(int a1, int a2, int a3, int a4, int a5, int a6 = 2, int a7 = 3)
{
	int sr = (a1 + a2 + a3 + a4 + a5 + a6 + a7) / 7;
	return sr;
}



int main()
{
	//Продемонстр. работу функций с общим кол-вом параметров 1,2,3,7
	/*
	cout << "\n0 = ";
	cout << Varparm::ivarparm(0);
	cout << "\n2 = ";
	cout << Varparm::ivarparm(1, 2);
	cout << "\n2*3 = ";
	cout << Varparm::ivarparm(2, 2, 3);
	cout << "\n1*2*3*4*5*6* = ";
	cout << Varparm::ivarparm(6, 1, 2, 3, 4, 5, 6);

	cout << "\n\n0 = ";
	cout << Varparm::svarparm(0);
	cout << "\n2 = ";
	cout << Varparm::svarparm(1, 2);
	cout << "\n2*3 = ";
	cout << Varparm::svarparm(2, 2, 3);
	cout << "\n1*2*3*4*5*6 = ";
	cout << Varparm::svarparm(6, 1, 2, 3, 4, 5, 6);

	cout << "\n\n1 = ";
	cout << Varparm::fvarparm(1.0, FLT_MAX);
	cout << "\n1+2 = ";
	cout << Varparm::fvarparm(1.0, 2.0, FLT_MAX);
	cout << "\n2+2+3 = ";
	cout << Varparm::fvarparm(2.0, 2.0, 3.0, FLT_MAX);
	cout << "\n6+2+3+4+5+6+7 = ";
	cout << Varparm::fvarparm(6.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, FLT_MAX);

	cout << "\n\n1 = ";
	cout << Varparm::dvarparm(1.0, DBL_MAX);
	cout << "\n1+2 = ";
	cout << Varparm::dvarparm(1.0, 2.0, DBL_MAX);
	cout << "\n2+2+3 = ";
	cout << Varparm::dvarparm(2.0, 2.0, 3.0, DBL_MAX);
	cout << "\n6+2+3+4+5+6+7 = ";
	cout << Varparm::dvarparm(6.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, DBL_MAX);



	int a = 2, b = 3, c = 5;
	int &aa = a, &bb = b, &cc = c;
	cout << "\n\n";
	cout << "2*3*5 = ";
	cout << Call::cdevl(aa, bb, cc);//3 по ссылке
	cout << "\n2*3*5 = ";
	cout << Call::cstd(aa, b, c);	//1 по ссылке, 2 по значению
	cout << "\n2*3*5 = ";
	cout << Call::cfst(a, b, c);	//3 по значению
	cout << endl;
	/*/
	
	//*
	cout << "\nResult of 5 par = ";
	cout << defaultparm(1, 2, 3, 4, 5);
	cout << "\nResult of 7 par = ";
	cout << defaultparm(1, 2, 3, 4, 5, 6, 7);
	//*/

	system("pause");
	return 0;
}