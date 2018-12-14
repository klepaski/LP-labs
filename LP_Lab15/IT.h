#pragma once
#define ID_MAXSIZE 5
#define TI_MAXSIZE 4096
#define TI_INT_DEFAULT 0x00000000
#define TI_STR_DEFAULT 0x00
#define TI_NULLIDX 0xffffffff
#define TI_STR_MAXSIZE 255
namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4 };//типы идентификаторов: переменная, функция, параметр, литерал
	struct Entry//строка таблицы идентификаторов
	{
		int idxfirstLE;//индекс первой строки в таблице лексем
		char id[ID_MAXSIZE];//идентификатор(автоматически усекается до ID_MAXSIZE)
		char fun[10];
		IDDATATYPE iddatatype;//тип данных
		IDTYPE idtype;//тип идентификатора
		char functionname[20];
		char lexes[2];
		union
		{
			int vint;//значение integer
			struct
			{
				int len;//количество символов в string
				char str[TI_STR_MAXSIZE - 1];//символы string
			}vstr;//значение string
		}value;//значение идентификатора
	};
	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};
	IdTable Create(int size);
	void Add(IdTable& idtable, Entry entry);
	Entry GetEntry(IdTable& idtable, int n);
	int IsId(IdTable& idtable, char id[ID_MAXSIZE]);
	void Delete(IdTable& idtable);
};