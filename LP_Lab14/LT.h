#pragma once
#define LEXEMA_FIXSIZE 1	//фиксированный размер лексем
#define LT_MAXSIZE 4096		//макс количество строк в таблице
#define LT_TI_NULLIDX 0xffffffff	//нет элемента ТИ
#define LEX_INTEGER		't'	//лексема для integer
#define LEX_STRING		't'	//лексема для string
#define LEX_LITERAL		'l'	//лексема для литерала
#define LEX_ID			'i'	//лексема для идентификатора
#define LEX_FUNCTION	'f'	//лексема для function
#define LEX_MAINFUNC	'm'	//лексема для main
#define LEX_DECLARE		'd'	//лексема для declare
#define LEX_RETURN		'r'	//return
#define LEX_PRINT		'p'	//print
#define LEX_SEMICOLON	';'	//;
#define LEX_COMMA		','	//,
#define LEX_LEFTBRACE	'{'	//{
#define LEX_BRACELET	'}'	//}
#define LEX_LEFTHESIS	'('	//(
#define LEX_RIGHTHESIS	')'	//)
#define LEX_PLUS		'v'	//+
#define LEX_MINUS		'v'	//-
#define LEX_STAR		'v'	//*
#define LEX_DIRSLASH	'v'	// /
#define LEX_RAV			'='	//=

namespace LT	//ТАБЛИЦА ЛЕКСЕМ
{
	struct Entry	//строка таблицы лексем
	{
		char lexema[LEXEMA_FIXSIZE];	///лексема
		int sn;			///№ строки в исх. тексте
		int idxTI;		///индекс в ТИ или в LT_TI_NULLIDX
	};

	struct LexTable		//экземпляр таблицы лексем
	{
		int maxsize;	///емкость ТЛ < LT_MAXSIZE
		int size;		///тек. размер ТЛ < maxsize
		Entry* table;	///массив строк ТЛ
	};

	LexTable Create( // создать таблицу лексем
		int size	/// емкость таблицы лексем < LT_MAXSIZE
	);
	void Add(				//добавить строку в таблицу лексем
		LexTable& lextable, ///экземпл¤р таблицы лексем
		Entry entry			///строка таблицы лексем
	);

	Entry GetEntry(			//получить строку таблицы лексем
		LexTable& lextable,	///экземпл¤р таблицы лексем
		int n				///номер получаемой строки
	);

	void Delete(LexTable& lextable); //удалить таблицу лексем (освободить пам¤ть)
};


