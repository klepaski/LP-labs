#pragma once
#include "FST.h"
#include "IT.h"
#include "LT.h"

namespace Checkup
{
	struct obl
	{
		char function[5];
		LT::LexTable lextab;
		IT::IdTable idtab;
	};
	bool proverka(char* m, FST::FST fst);
	void paste(int line, char m);
	void Leksika(Parm::PARM parm, In::IN in);
};
