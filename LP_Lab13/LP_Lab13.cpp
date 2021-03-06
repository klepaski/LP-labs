// 13lp.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "FST.h"
#include "In.h"
#include <cwchar>
#include <time.h>



int _tmain(int argc, _TCHAR* argv[])
{
	Log::LOG log = Log::INITLOG;
	setlocale(LC_ALL, "Russian");
	std::cout << "----------------------------LOG--------------------------------------" << std::endl;

	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl;
		log = Log::getlog(parm.log);
		char str1[] = "Test: ";
		char str2[] = "Without mistake";
		char str3[] = "";
		Log::WriteLine(log, str1, str2, str3);
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);

		wchar_t wstr1[] = L"Test: ";
		wchar_t wstr2[] = L"Without mistake";
		wchar_t wstr3[] = L"";
		Log::WriteLine(log, wstr1, wstr2, wstr3);
		std::cout << in.text << std::endl;
		Log::Close(log);
		std::cout << "------------------------------------------------------------------" << std::endl;

		FST::resolveChain((char*)in.text);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}

	system("pause");
	return 0;
}
