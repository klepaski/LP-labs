// LPLab10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Error.h"		//обработка ошибок
#include "Parm.h"		//обработка параметров
#include "Log.h"		//работа с протоколом
#include "In.h"			//ввод исходного файла
#include <cwchar>
#include <time.h>


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"russian");

	std::cout << "---------------------------------geterror--------------------------------" << std::endl;
	try
	{
		throw ERROR_THROW(1111);
	}
	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Message: " << e.message << std::endl << std::endl;
	}


	std::cout << "-------------------------------geterrorin--------------------------------" << std::endl;

	try
	{
		throw ERROR_THROW_IN(111, 7, 7);	///Недопустимый символ в исходном файле (-in)
	}

	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Message: " << e.message << " Line: " << e.inext.line << " Col:" << e.inext.col << std::endl << std::endl;
	}


	std::cout << "--------------------------------getparm----------------------------------" << std::endl;
	try
	{
		Parm::PARM parm1 = Parm::getparm(argc, argv);
		std::wcout << "-in:" << parm1.in << ", -out:" << parm1.out << ", -log:" << parm1.log << std::endl << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Message: " << e.message << " Line: " << e.inext.line << " Col:" << e.inext.col << std::endl;
	}



	std::cout << "---------------------------------getin-----------------------------------" << std::endl;
	try
	{
		Parm::PARM parm2 = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm2.in);
		std::cout << in.text << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e)
	{
		std::cout << "ID: " << e.id << " Message: " << e.message << " Line: " << e.inext.line << " Col:" << e.inext.col << std::endl;
	}
	std::cout << "-------------------------------------------------------------------------" << std::endl;


	Log::LOG log = Log::INITLOG;

	try
	{
		Parm::PARM parm3 = Parm::getparm(argc, argv);
		log = Log::getlog(parm3.log);

		Log::WriteLine(log, "Тест: ", "Без ошибок", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm3);
		In::IN in = In::getin(parm3.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	};
	system("pause");

	return 0;
}
