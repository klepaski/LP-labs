#include "stdafx.h"
#include "Varparm.h"
#include <cstdarg>
#include <locale>

namespace Varparm
{
	//������������ ���������� ������� �� 2-��� (int)
	int ivarparm(int n, ...)
	{
		int k = 1;
		if (n == 0) return 0;

		int *f = &n;	///��������� �� ������ �������� (���-��)
		f = (f + 1);	///������� �� ����. ��������

		for (int i = 0; i < n; i++)
		{
			k = k* (*f);
			f = (f + 1);
		}
		return k;
	}


	//������������ ���������� ������� �� 2-���
	int  svarparm(short n, ...)
	{
		short k = 1;
		if (n == 0) return 0;

		short *l = &n;	///��������� �� ������ �������� (���-��)
		l = (l + 2);	///��������� �� ����. ��������

		for (int i = 0; i < n; i++)
		{
			k = k * (*l);
			l = (l + 2);
		}
		return (int)k;	///����������� ��������� � int
	}


	//����� ����������, ������� � ������� �� �������������
	double fvarparm(float f, ...)
	{
		///�. � ���������� ������ ���������� �. ����� ���� 1 ��������� �������� (����. ������� ...)
		va_list arg;
		///����� �������� � ���������� ���������� ����� ������������� arg
		///��������� ������ ����������
		va_start(arg, f);

		float f1 = 0, f2 = f;
		while (f1 != FLT_MAX)
		{
			f1 = va_arg(arg, double);///����� �������� �� ������ ����������
			if (f1 != FLT_MAX)
				f2 += f1;
		}
		///��������� ��������� ������ ����������
		va_end(arg);
		return (double)f2;
	}


	//����� ����������, ������� � ������� �� �������������
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