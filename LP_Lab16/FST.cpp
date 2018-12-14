#include "stdafx.h"
#include "FST.h"
#include<utility>
#include<fstream>
namespace FST
{
	RELATION::RELATION(char c, short nn)
	{
		symbol = c;
		nnode = nn;
	};
	NODE::NODE()
	{
		n_relation = 0;
		RELATION *relations = NULL;
	};
	NODE::NODE(short n, RELATION rel, ...)
	{
		n_relation = n;
		RELATION *p = &rel;
		relations = new RELATION[n];
		for (short i = 0; i < n; i++)
		{
			relations[i] = p[i];
		}
	};
	FST::FST(char *s, short ns, NODE n, ...)
	{
		string = s;
		nstates = ns;
		nodes = new NODE[ns];
		NODE*p = &n;
		for (int k = 0; k < ns; k++)
		{
			nodes[k] = p[k];
		}
		rstates = new short[nstates];
		memset(rstates, 0xff, sizeof(short)*nstates);
		rstates[0] = 0;
		position = -1;
	};
	bool step(FST& fst, short* &rstates)
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
					}
				}
		}
		return rc;
	}
	bool execute(FST &fst)
	{
		short *rstates = new short[fst.nstates];
		memset(rstates, 0xff, sizeof(short)*fst.nstates);
		short lstring = strlen(fst.string);
		bool rc = true;
		for (short i = 0; i < lstring && rc; i++)
		{
			fst.position++;
			rc = step(fst, rstates);
		}
		fst.rstates[0] = 0;
		//delete[] rstates;
		return(rc ? (fst.rstates[fst.nstates - 1] == lstring) : rc);
	}
	void Analyze(Parm::PARM p)
	{
		int position = 0, line = 1;
		static std::ifstream stream1(p.in);
		static std::ofstream stream(p.out);
		char ch[2] = "a";
		char g[1024];
		char f[1024] = "";
		while (!stream1.eof())
		{
			ch[0] = stream1.get();
			do
			{
				strcat(f, ch);
				position++;
				ch[0] = stream1.get();
			} while (ch[0] != '|' && !stream1.eof());
			strcpy(g, f);
			FST fst2(
				g,
				9,
				NODE(1, RELATION('j', 1)),
				NODE(2, RELATION(' ', 1), RELATION('~', 2)),
				NODE(3, RELATION('f', 3), RELATION('h', 4), RELATION('~', 6)),
				NODE(1, RELATION(';', 4)),
				NODE(1, RELATION(' ', 5)),
				NODE(3, RELATION(' ', 5), RELATION(';', 6), RELATION(';', 2)),
				NODE(2, RELATION(' ', 6), RELATION('g', 7)),
				NODE(1, RELATION(';', 8)),
				NODE()
			);
			if (execute(fst2))
			{
				stream << "Цепочка " << fst2.string << " распознана" << std::endl;
			}
			else
			{
				stream << "Ошибка в " << line << " линии, " << fst2.position + 1 << " позиция" << std::endl;
			}
			line++;
			position = 0;
			strcpy(f, "");
		}
		stream.close();
		stream1.close();
	}
};