// LP_Lab04.cpp : Defines the entry point for the console application.
// X=36, Y=37, Z=38, S=1.27

#include "stdafx.h"
#include <iostream>
#include <string>

///
// 36 - 0010 0100
//		  2	   4		=0х24
///int 4, short 2, long 4, wchar_t 2
///float 4, long 4, double 8, long double 10

int fun(int a) { return a + 5; }

int main()
{
	bool b1 = true;
	bool b2 = false;

	char ch1 = 'Q';
	wchar_t wch1 = L'н';

	short s1=36; //0010 0100(2) - 0х24
	short s2=-36; //FFFF FFFF FFFF FFDC
	//8
	short minSh = 0x8001;
	short maxSh = 0x7FFF;
	//9
	unsigned short minU_Sh = 0;
	unsigned short maxU_Sh = 0xFFFF;
	//10
	int i1 = 37;	//0010 0101(2) - 0х25
	int i2 = -37;	//FFFF FFFF FFFF FFDB
	//11
	int maxI = 0x7FFFFFFF;
	int minI = 0x80000001;
	//12
	unsigned int maxU_I = 0xFFFFFFFF;
	unsigned int minU_I = 0x0;
	//13
	long l1 = 38;	//0010 0110(2) - 0х26
	long l2 = -38;	//FFFF FFFF FFFF FFDA
	//14
	long maxL = 0x7FFFFFFF;
	long minL = 0x80000001;
	//15
	unsigned long maxU_L = 0xFFFFFFFF;
	unsigned long minU_L = 0x0;
	//16
	float f1 = 1.27;	//0001.0100 0101(2) - 1.45
	float f2 = -1.27;	//FFFF FFFF FFFF FFFF.45
	//17
	float x = 1, y = 0;
	float S1 = x / y;  //1.#INF
	float S2 = -x / y; //-1.#INF
	float S3 = S2 + 1; //-1.IND
	//18
	char *pch = &ch1;
	wchar_t *pwch = &wch1;
	short *psh = &s1;
	int *pi = &i1;
	float *pf = &S1;
	double d1 = 2.35; double *pd = &d1;
	*pch += 3;
	*pwch += 3;
	*psh += 3;
	*pi += 3;
	*pf += 3;
	*pd += 3;
	//19
	int(*pff)(int);
	pff = &fun;
	//20
	char &lch = ch1;
	wchar_t &lwch = wch1;
	short &lsh = s1;
	int &li = i1;
	float &lf = f1;
	double &ld = d1;

	system("pause");
	return 0;
}



