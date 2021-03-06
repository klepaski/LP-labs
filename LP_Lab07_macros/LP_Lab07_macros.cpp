// macros.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dict.h"
using namespace Dictionary;

#if (defined(TEST_CREATE_01) + defined(TEST_CREATE_02) + defined(TEST_ADDENTRY_03) + defined(TEST_ADDENTRY_04) + defined(TEST_GETENTRY_05) + defined(TEST_DELENTRY_06) + defined(TEST_UPDENTRY_07) + defined(TEST_UPDENTRY_08) > 1) 
#error С помощью #define объявлено более одной ошибки;
#endif

int main()
{
	setlocale(LC_ALL, "rus");
	try {
		Instance d3 = Create("Преподаватели", 5);
		Entry e1 = { 1,"Гладкий" }, //элементы словаря
			  e2 = { 2,"Веялкин" },
			  e3 = { 3,"Смелов" },
			  e4 = { 4,"Урбанович" },
			  e5 = { 5,"Пацей" },
			  e6 = { 31,"Чистякова" };
		AddEntry(d3, e4);
	//-------------------------------------------
	#ifdef TEST_CREATE_01
			Instance d4 = Create("Преподаватеееееееееееели", 5);
	#endif 
	//-------------------------------------------
	#ifdef TEST_CREATE_02
			Instance d5 = Create("Преподаватели", DICTMAXSIZE + 1);
	#endif
	//-------------------------------------------
	#ifdef TEST_ADDENTRY_03
			AddEntry(d3, e6);
	#endif
	//-------------------------------------------
	#ifdef TEST_ADDENTRY_04
			AddEntry(d3, e2);
			AddEntry(d3, e2);
	#endif
	//-------------------------------------------
	#ifdef TEST_GETENTRY_05
			Entry ex05 = GetEntr(d3, 10);
	#endif
	//-------------------------------------------
	#ifdef TEST_DELENTRY_06
			DelEntry(d3, 7);
	#endif
	//-------------------------------------------
	#ifdef TEST_UPDENTRY_07
			Entry newentry1 = { 6,"Гурин" };
			UpdEntry(d3, 8, newentry1);
	#endif
	//-------------------------------------------
	#ifdef TEST_UPDENTRY_08
			Entry newentry1 = { 4,"Гурин" };
			UpdEntry(d3, 4, newentry1);
	#endif
	//-------------------------------------------
	#ifdef  TEST_DICTIONARY
			Instance d1 = Create("Преподаватели", 7);
			Entry e11 = { 1,"Гладкий" }, //элементы словаря
				  e12 = { 2,"Веялкин" },
				  e13 = { 3,"Смелов" },
				  e14 = { 4,"Урбанович" },
				  e15 = { 5,"Пацей" },
				  e16 = { 6,"Иванов" },
				  e17 = { 7,"Горин" };
			AddEntry(d1, e11);
			AddEntry(d1, e12);
			AddEntry(d1, e13);
			AddEntry(d1, e14);
			AddEntry(d1, e15);
			AddEntry(d1, e16);
			AddEntry(d1, e17);
			Print(d1);
			//-------------------------------------------
			Instance d2 = Create("Студенты", 7);
			Entry e01 = { 1,"Каспер" },
				  e02 = { 2,"Чистякова" },
				  e03 = { 3,"Хорошко" },
				  e04 = { 4,"Муха" },
				  e05 = { 5,"Лэ" },
				  e06 = { 6,"Жмур" },
				  e07 = { 7,"Сойкель" };
			AddEntry(d2, e01);
			AddEntry(d2, e02);
			AddEntry(d2, e03);
			AddEntry(d2, e04);
			AddEntry(d2, e05);
			AddEntry(d2, e06);
			AddEntry(d2, e07);
			Print(d2);
			Delete(d1);
			Delete(d2);
	#endif
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	};
	system("pause");
	return 0;
}