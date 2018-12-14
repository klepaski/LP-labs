// YAP14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "IT.h"
#include "LT.h"
#include "FST.h"
#include "Check.h"
#include "GRB.h"
#include "MFST.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	Log::LOG log = Log::INITLOG;
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);
	try
	{
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

