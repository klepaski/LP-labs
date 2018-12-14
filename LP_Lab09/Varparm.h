#pragma once

namespace Varparm
{
	int ivarparm(int n, ...);		//произведение параметров, начиная со второго
									//n - кол-во перемножаемых параметров

	int  svarparm(short n, ...);

	double fvarparm(float f, ...);	//сумма параметров с первого по предпоследний
									//переменное кол-во параметров
									//посл.пар. - макс число типа float (исп. станд. макрос)

	double dvarparm(double d, ...);
}