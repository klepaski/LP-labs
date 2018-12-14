#pragma once
#define IN_MAX_LEN_TEXT 512*512		//макс.размер исходного кода
#define IN_CODE_ENDL '\n'
#define IN_CODE_TABLE {\
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::I,   '!', IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::T, IN::F, IN::T, IN::T, IN::F, IN::F, IN::T, \
	IN::F, IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, IN::F, IN::T, IN::T, IN::F, IN::F, IN::T, IN::F, IN::F, \
																													\
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
	IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, \
	IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::T, IN::F, IN::F, IN::T, IN::F, \
	IN::F, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, \
}

namespace In {
	struct IN			//исходные данные
	{
		enum { T = 1024, F = 2048, I = 4096 };
		int size;						//р-р исходного кода
		int lines;						//кол-во строк
		int ignor;						//кол-во проигнор. символов
		unsigned char *text;			//исходный код(Windows-1251)
		int code[256] = IN_CODE_TABLE;	//таблица проверки: T,F,I, новое значение
	};
	IN getin(wchar_t infile[]);			//ввести и проверить входной поток
}
/*
C  h   i   s   t   y   a   k   o   v   a      J   u   l   i   a
67 104 105 115 116 121 97 107 111 118  97     74  117 108 105 97
„   и   с   т   €   к   о   в   а       ё   л   и   €
215 232 241 242 255 234 238 226 224     222 235 232 255
*/