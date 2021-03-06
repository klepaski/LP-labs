// LP_Lab07.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>
#include <locale>

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "rus");
	try {
		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 4); //создание словаря
		Dictionary::Entry e1 = { 1,"Гладкий" },		//элементы словаря
						  e2 = { 2,"Веялкин" },
						  e3 = { 3,"Смелов" },
						  e4 = { 4,"Урбанович" };
						 // e5 = { 5,"Пацей" };
		Dictionary::AddEnrty(d1, e1);						 //добавление элемента в словарь
		Dictionary::AddEnrty(d1, e2);
		Dictionary::AddEnrty(d1, e3);
		Dictionary::AddEnrty(d1, e4);
		Dictionary::Entry ex2 = Dictionary::GetEntr(d1, 4);  //найти элемент в словаре по id 4
		Dictionary::DelEntry(d1, 4);						 //удалить элемент в словаре по id
		Dictionary::Entry newentry1 = { 6,"Гурин" };		 //элемент словаря
		Dictionary::UpdEntry(d1, 3, newentry1);				 //заменить эл-т словаря по id
		Dictionary::Print(d1);								 //распечатать эл-ты словаря



		Dictionary::Instance d2 = Dictionary::Create("Студенты", 3);
		Dictionary::Entry s1 = { 1, "Иванов" },
						  s2 = { 2, "Петров" },
						  s3 = { 3, "Сидоров" };
		Dictionary::AddEnrty(d2, s1);
		Dictionary::AddEnrty(d2, s2);
		Dictionary::AddEnrty(d2, s3);
		//Dictionary::Entry newentry3 = { 3, "Николаев" };
		//Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);

		Delete(d1);
		Delete(d2);
	}
	catch (const char* e) {					//обработка исключений словаря
		std::cout << e << std::endl;
	};
	system("pause");
	return 0;
}