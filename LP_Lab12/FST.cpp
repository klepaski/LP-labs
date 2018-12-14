#include "stdafx.h"
#include "FST.h"
#include <iostream>

FST::RELATION::RELATION(char c, short ns)
{
	symbol = c;
	nnode = ns;
};

FST::NODE::NODE()
{
	n_relation = 0;
	RELATION * relations = NULL;
};

FST::NODE::NODE(short n, RELATION rel, ...)
{
	n_relation = n;
	RELATION *p = &rel;
	relations = new RELATION[n];
	for (short i = 0; i < n; i++) relations[i] = p[i];
};

FST::FST::FST(char * s, short ns, NODE n, ...)
{
	string = s;
	nstates = ns;
	nodes = new NODE[ns];
	NODE *p = &n;
	for (int k = 0; k < ns; k++) nodes[k] = p[k];
	rstates = new short[nstates];
	memset(rstates, 0xff, sizeof(short)* nstates);
	rstates[0] = 0;
	position = -1;
};



bool FST::execute(FST & fst)
{
	short* rstates = new short[fst.nstates]; memset(rstates, 0xff, sizeof(short)*fst.nstates);
	short lstring = strlen(fst.string);
	bool rc = true;
	for (short i = 0; i < lstring && rc; i++)
	{
		fst.position++;
		rc = step(fst, rstates);
	};
	delete[] rstates;
	return (rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
};


bool FST::step(FST& fst, short* &rstates)
{
	bool rc = false;
	std::swap(rstates, fst.rstates);
	for (short i = 0; i < fst.nstates; i++)
	{
		if (rstates[i] == fst.position)
			for (short j = 0; j < fst.nodes[i].n_relation; j++)
			{
				if (fst.nodes[i].relations[j].symbol == fst.string[fst.position])
				{
					fst.rstates[fst.nodes[i].relations[j].nnode] = fst.position + 1;
					rc = true;
				};
			}
	};
	return rc;
};


void FST::myFunc(char *string)
{
	FST fst(
		string,
		9,
		NODE(1, RELATION('m', 1)),
		NODE(3, RELATION('b', 2), RELATION('b', 1), RELATION('b', 5)),
		NODE(3, RELATION('s', 3), RELATION('w', 3), RELATION('h', 3)),
		NODE(1, RELATION(';', 4)),
		NODE(3, RELATION('b', 5), RELATION('b', 4), RELATION('b', 2)),
		NODE(2, RELATION('b', 6), RELATION('b', 5)),
		NODE(1, RELATION('r', 7)),
		NODE(1, RELATION(';', 8)),
		NODE()
	);
	if (execute(fst))
	{
		std::cout << "chain \"" << fst.string << "\" is recognized" << std::endl;
	}
	else
	{
		std::cout << "chain \"" << fst.string << "\" is't recognized" << std::endl;

	}
};
