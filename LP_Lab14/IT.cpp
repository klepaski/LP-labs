#include "stdafx.h"
#include "IT.h"
#include "Error.h"

namespace IT
{
	IdTable Create(int size)				//Создать ТИ
	{
		IdTable* tabl = new IdTable;
		if (size > TI_MAXSIZE)
		{
			throw ERROR_THROW(115);		///Заданное количество строк > 4096
		}
		tabl->maxsize = size;
		tabl->size = 0;
		tabl->table = new Entry[size];	///новая строка ТИ
		return*tabl;
	}

	void Add(IdTable& idtable, Entry entry)	//Добавить строку в ТИ
	{
		if (idtable.size + 1 > idtable.maxsize)
		{
			throw ERROR_THROW(116);		///Превышено количество строк в ТИ
		}

		idtable.table[idtable.size] = entry;
		idtable.size += 1;
	}

	Entry GetEntry(IdTable& idtable, int n)	//Возвр. ид. по номеру строки
	{
		return idtable.table[n];
	}

	int IsId(IdTable& idtable, char id[ID_MAXSIZE])	//Возвр. № строки
	{
		int n = 0;
		bool flag_s = false;
		while (n < idtable.size - 1)
		{
			if (idtable.table[n].id == id)	///когда  в ТИ найден искомый идент.
			{
				flag_s = true;
				break;
			}
			n += 1;
		}
		if (flag_s)
		{
			return n + 1;		///номер его строки
		}
		else
		{
			return TI_NULLIDX;	///если заданной строки нет
		}
	}

	void Delete(IdTable& idtable)	//Удалить ТИ
	{
		delete[] idtable.table;
		//delete &idtable;
	}
};