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
	void zapol(int line, char m);
	void Probel(Parm::PARM parm);
	void Leksika(Parm::PARM parm, In::IN in);
	bool PolishNotation(int pos, LT::LexTable &lextb, IT::IdTable &idtb);
};
