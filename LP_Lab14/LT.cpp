#include "stdafx.h"
#include <iostream>
#include "LT.h"
#include "Error.h"

namespace LT
{
	LexTable Create(int size)			//Создать ТЛ
	{
		LexTable* tabl = new LexTable;
		if (size > LT_MAXSIZE)///4096
		{
			throw ERROR_THROW(113);		///Заданное количество строк в ТЛ > 4096
		}
		tabl->maxsize = size;
		tabl->size = 0;
		tabl->table = new Entry[size];	///новая строка ТЛ
		return *tabl;
	}

	void Add(LexTable& lextable, Entry entry)	//Добавить строку в ТЛ
	{
		if (lextable.size + 1 > lextable.maxsize)
		{
			throw ERROR_THROW(114);		///Превышено количество строк в ТЛ
		}

		lextable.table[lextable.size] = entry;
		lextable.size += 1;
	}
	Entry GetEntry(LexTable& lextable, int n)	//Получить строку по №
	{
		return lextable.table[n];
	}
	void Delete(LexTable& lextable)	//Удалить ТЛ
	{
		delete[] lextable.table;
		//delete &lextable;
	}
};