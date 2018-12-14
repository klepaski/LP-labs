// YAP14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	Log::LOG log = Log::INITLOG;
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);

	In::IN in = In::getin(parm.in);
	//-----------------------
	Log::WriteLog(log);
	Log::WriteParm(log, parm);
	Log::WriteIn(log, in);



	try
	{
	
		Checkup::Leksika(parm, in);
		
	}
	catch (Error::ERROR e)
	{
		WriteError(log, e);
	};
	system("pause");
	return 0;
}