#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cwchar>
#include "In.h"
#include "Error.h"

namespace In {
	IN getin(wchar_t infile[])
	{
		IN IN;

		IN.size = 0;
		IN.lines = 0;
		std::ifstream fin;
		std::string Buff;
		unsigned char textTemp[IN_MAX_LEN_TEXT];
		IN.ignor = 0;
		fin.open(infile);
		if (fin.fail())
		{
			throw ERROR_THROW(110); ///Ошибка при открытии файла с исходным кодом (-in)
		}
		for (int t = 0;;)
		{
			getline(fin, Buff);

			for (int i = 0; i < Buff.length(); ++i)
			{
				if (IN.code[(int)Buff[i]] == IN::F)
				{
					throw ERROR_THROW_IN(111, IN.lines, i);	///Недопустимый символ в исходном файле (-in)
				}
				else if (IN.code[(int)Buff[i]] == IN::I)
				{
					IN.ignor++;
				}
				else
				{
					IN.size++;
					textTemp[t] = Buff[i];
					++t;
				}
			}
			IN.lines++;
			IN.size++;
			textTemp[t] = IN_CODE_ENDL;
			t++;
			if (fin.eof())
			{
				textTemp[t] = '\0';
				break;
			}
		}
		IN.text = textTemp;
		fin.close();
		return IN;
	}
}