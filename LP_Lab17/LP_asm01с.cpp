#include "stdafx.h"
#include <iostream>
#pragma comment (lib, "..\\Debug\\LP_asm01a.lib")

extern "C" ///связ. по типу С, чтобы обойти декорирование в языке С++ при объявлении и определении функций
{
	int _stdcall getmax(int*, int);
	int _stdcall getmin(int*, int);
}

int main()
{
	int mas[10] = { -10, 15, -23, 4, 2, 8, 34, 11, -16, 27 };
	int max = getmax(mas, sizeof(mas) / sizeof(int));
	int min = getmin(mas, sizeof(mas) / sizeof(int));
	std::cout << "getmax-getmin=" << max - min << std::endl;
	return 0;
}