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
	bool check(char* m, FST::FST fst);
	void fill(int line, char m);
	void Leksika(Parm::PARM parm, In::IN in);
	bool PolishNotation(int lextable_pos, LT::LexTable &lextab, IT::IdTable &idtab);

};
