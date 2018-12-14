// YAP14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		In::IN in = In::getin(parm.in);
		Checkup::Leksika(parm, in);
	}
	catch (Error::ERROR e)
	{
		WriteError(log, e);
	};
	system("pause");
	return 0;
}