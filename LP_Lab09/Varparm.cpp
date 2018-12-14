#include "stdafx.h"
#include "Varparm.h"
#include <cstdarg>
#include <locale>

namespace Varparm
{
	//произведение параметров начиная со 2-ого (int)
	int ivarparm(int n, ...)
	{
		int k = 1;
		if (n == 0) return 0;

		int *f = &n;	///указатель на первый параметр (кол-во)
		f = (f + 1);	///переход на след. параметр

		for (int i = 0; i < n; i++)
		{
			k = k* (*f);
			f = (f + 1);
		}
		return k;
	}


	//произведение параметров начиная со 2-ого
	int  svarparm(short n, ...)
	{
		short k = 1;
		if (n == 0) return 0;

		short *l = &n;	///указатель на первый параметр (кол-во)
		l = (l + 2);	///указатель на след. параметр

		for (int i = 0; i < n; i++)
		{
			k = k * (*l);
			l = (l + 2);
		}
		return (int)k;	///преобразуем результат в int
	}


	//сумма параметров, начиная с первого по предпоследний
	double fvarparm(float f, ...)
	{
		///ф. с переменным числом аргументов д. иметь хоть 1 известный параметр (указ. вначале ...)
		va_list arg;
		///перед доступом к параметрам переменной длины инициализация arg
		///указатель списка параметров
		va_start(arg, f);

		float f1 = 0, f2 = f;
		while (f1 != FLT_MAX)
		{
			f1 = va_arg(arg, double);///берет аргумент из списка параметров
			if (f1 != FLT_MAX)
				f2 += f1;
		}
		///закрывает указатель списка параметров
		va_end(arg);
		return (double)f2;
	}


	//сумма параметров, начиная с первого по предпоследний
	double dvarparm(double d, ...)
	{
		va_list arg;
		va_start(arg, d);
		double d1 = 0, d2 = d;
		while (d1 != DBL_MAX)
		{
			d1 = va_arg(arg, double);
			if (d1 != DBL_MAX)
			{
				d2 += d1;
			}
		}
		va_end(arg);
		return d2;
	}
}