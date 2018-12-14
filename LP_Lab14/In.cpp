#include "stdafx.h"
#include "In.h"
#include "Error.h"
#include <iostream>
#include <fstream>
namespace In
{
	IN getin(wchar_t infile[])
	{
		IN f;
		unsigned char ch = 'a';
		static unsigned char l[1024] = "";
		int line = 0, position = 0, size = 0, ignor = 0, i = 0;
		std::ifstream in(infile);

		if (in.fail() == 0)
		{
			ch = in.get();			///получ. символ из файла
			while (!in.eof())
			{
				if (ch == ((unsigned char)'\n'))
				{
					line++;
				}
				if (f.code[(int)ch] == IN::T)
				{
					position++;
					l[i] = ch;
					i++;
				}
				else if (f.code[(int)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, line, position);	///Недопустимый символ в исходном коде
				}
				else if (f.code[(int)ch] == IN::I)
				{
					ignor++;
				}
				ch = in.get();
			}
			in.close();
			f.size = i;			///кол-во символов
			f.text = l;			///текст в исх. коде
			f.lines = line;		///кол-во строк в файле
			f.ignor = ignor;	///кол-во проигнорированных

		}
		else
		{
			throw ERROR_THROW(110);	///Ошибка при открытии файла с исходным кодом
		}
		return f;
	}
};