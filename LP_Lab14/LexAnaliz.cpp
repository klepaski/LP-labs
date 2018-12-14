#include "stdafx.h"

///�� ����. ��. ����. ����.
FST::FST typeint("", 8,
	FST::NODE(1, FST::RELATION('i', 1)),
	FST::NODE(1, FST::RELATION('n', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('e', 4)),
	FST::NODE(1, FST::RELATION('g', 5)),
	FST::NODE(1, FST::RELATION('e', 6)),
	FST::NODE(1, FST::RELATION('r', 7)),
	FST::NODE()
);

FST::FST typestring("", 7,
	FST::NODE(1, FST::RELATION('s', 1)),
	FST::NODE(1, FST::RELATION('t', 2)),
	FST::NODE(1, FST::RELATION('r', 3)),
	FST::NODE(1, FST::RELATION('i', 4)),
	FST::NODE(1, FST::RELATION('n', 5)),
	FST::NODE(1, FST::RELATION('g', 6)),
	FST::NODE()
);

FST::FST typefunction("", 9,
	FST::NODE(1, FST::RELATION('f', 1)),
	FST::NODE(1, FST::RELATION('u', 2)),
	FST::NODE(1, FST::RELATION('n', 3)),
	FST::NODE(1, FST::RELATION('c', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE(1, FST::RELATION('i', 6)),
	FST::NODE(1, FST::RELATION('o', 7)),
	FST::NODE(1, FST::RELATION('n', 8)),
	FST::NODE()
);

FST::FST strdeclare("", 8,
	FST::NODE(1, FST::RELATION('d', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('c', 3)),
	FST::NODE(1, FST::RELATION('l', 4)),
	FST::NODE(1, FST::RELATION('a', 5)),
	FST::NODE(1, FST::RELATION('r', 6)),
	FST::NODE(1, FST::RELATION('e', 7)),
	FST::NODE()
);

FST::FST streturn("", 7,
	FST::NODE(1, FST::RELATION('r', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('u', 4)),
	FST::NODE(1, FST::RELATION('r', 5)),
	FST::NODE(1, FST::RELATION('n', 6)),
	FST::NODE()
);

FST::FST strmain("", 5,
	FST::NODE(1, FST::RELATION('m', 1)),
	FST::NODE(1, FST::RELATION('a', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE()
);

FST::FST strprint("", 6,
	FST::NODE(1, FST::RELATION('p', 1)),
	FST::NODE(1, FST::RELATION('r', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE(1, FST::RELATION('t', 5)),
	FST::NODE()
);

FST::FST expression("", 2,
	FST::NODE(4,
		FST::RELATION('+', 1),
		FST::RELATION('-', 1),
		FST::RELATION('*', 1),
		FST::RELATION('/', 1)),
	FST::NODE()
);

FST::FST probel("", 2,
	FST::NODE(1, FST::RELATION(' ', 1)),
	FST::NODE()
);

FST::FST leftbrace("", 2,
	FST::NODE(1, FST::RELATION('{', 1)),
	FST::NODE()
);

FST::FST rightbrace("", 2,
	FST::NODE(1, FST::RELATION('}', 1)),
	FST::NODE()
);

FST::FST leftthesis("", 2,
	FST::NODE(1, FST::RELATION('(', 1)),
	FST::NODE()
);

FST::FST rightthesis("", 2,
	FST::NODE(1, FST::RELATION(')', 1)),
	FST::NODE()
);

FST::FST semicolon("", 2,
	FST::NODE(1, FST::RELATION(';', 1)),
	FST::NODE()
);

FST::FST comma("", 2,
	FST::NODE(1, FST::RELATION(',', 1)),
	FST::NODE()
);

FST::FST plus("", 2,
	FST::NODE(1, FST::RELATION('+', 1)),
	FST::NODE());

FST::FST minus("", 2,
	FST::NODE(1, FST::RELATION('-', 1)),
	FST::NODE());

FST::FST del("", 2,
	FST::NODE(1, FST::RELATION('/', 1)),
	FST::NODE());

FST::FST umn("", 2,
	FST::NODE(1, FST::RELATION('*', 1)),
	FST::NODE());

FST::FST ravno("", 2,
	FST::NODE(1, FST::RELATION('=', 1)),
	FST::NODE());

FST::FST Literal("", 2,
	FST::NODE(20,
		FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
		FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
		FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
		FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
		FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
		FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
		FST::RELATION('8', 1), FST::RELATION('9', 1)),
	FST::NODE()
);

FST::FST fstidenf("", 2,
	FST::NODE(54, 
		FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
		FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
		FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
		FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
		FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
		FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
		FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
		FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
		FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
	FST::NODE()
);
LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);
std::fstream file;


namespace Checkup
{
	bool proverka(char* m, FST::FST fst)
	{
		fst.string = m;
		return FST::execute(fst);
	}


	void paste(int line, char m)
	{
		LT::Entry entry;
		entry.sn = line;
		if (m != 'i')
		{
			entry.idxTI = LT_TI_NULLIDX;
		}
		else
		{
			entry.idxTI = idtab.size;
		}
		memset(entry.lexema, '\0', strlen(entry.lexema) - 1);
		entry.lexema[0] = m;
		LT::Add(lextab, entry);
	}

	void Leksika(Parm::PARM parm, In::IN in)
	{
		char word[255] = "";
		char word2[255] = "";
		bool flagfun2 = false;
		int m = 0;
		int line = 1;
		bool nai = false;		///���� ���� ����, ����� �������
		bool povt_id = false;
		char ch;
		bool flag_s = false;
		bool flag_i = false;
		bool pflag = false;		///���� ���������
		bool id = false;
		char lit = '0';
		bool flag_lit = false;
		int n = 0;
		IT::Entry entr;
		bool funflag = false;
		short odin = 0;			/// '
		char fun[10] = "global";
		char fun2[10] = "global";
		bool povt_lit = false;

		for (int i = 0; i < in.size; i++)
		{
			ch = in.text[i];
			nai = false;				///���� ����. ����
			if (ch == IN_CODE_ENDL)
			{
				line++;
				paste(line, '|');
				continue;
			}
			if (ch == '\'')
			{
				odin++;
				if (odin == 2)
					odin = 0;
			}
			if (odin == 1)
			{
				word[m] = ch;
				m++;
				continue;
			}

			
			if (ch != ' ' && ch != ';' && ch != '-' && ch != '+' && ch != '/' && ch != '*' && ch != '\''
				&& ch != ','&&ch != ')' && ch != '(' && ch != '}' && ch != '{' && ch != IN_CODE_ENDL && ch != '=')
			{
				word[m] = ch;
				m++;
				continue;
			}

			///�������� �� �������� �����
			else
			{
				word[m] = '\0';
				m = 0;

				if (ch == IN_CODE_ENDL)
				{
					line++;
					continue;
				}
				nai = proverka(word, typestring);	///�������� �� string
				if (nai)
				{
					paste(line, LEX_STRING);
					flag_s = true;
				}
				if (!nai)
				{
					nai = proverka(word, typeint);	///�������� �� int
					if (nai)
					{
						flag_i = true;
						paste(line, LEX_INTEGER);
					}
				}
				if (!nai)
				{
					nai = proverka(word, typefunction);	///�������� �� function
					if (nai)
						paste(line, LEX_FUNCTION);
				}
				if (!nai)
				{
					nai = proverka(word, strdeclare);	///�������� �� declare
					if (nai)
						paste(line, LEX_DECLARE);
				}
				if (!nai)
				{
					nai = proverka(word, streturn);	///�������� �� return
					if (nai)
						paste(line, LEX_RETURN);
				}
				if (!nai)
				{
					nai = proverka(word, strmain);	///�������� �� main
					if (nai)
					{
						paste(line, LEX_MAINFUNC);
						strcpy(fun, "main");

					}

				}
				if (!nai)
				{
					nai = proverka(word, strprint);	///�������� �� print
					if (nai)
						paste(line, LEX_PRINT);
				}

				///��������� �������
				if (word[0] == '\'')
				{
					paste(line, LEX_LITERAL);/// l
					for (int i = 0; i < strlen(word); i++)
						word2[i] = word[i + 1];	///��� �������
					word2[strlen(word)] = '\0';
					nai = true;					///��������� ������� - ��. �������� �� �����
					flag_lit = true;
					flag_s = true;
				}
				
				///������������� �������
				if (!nai)
				{
					nai = proverka(word, Literal);
					if (nai)
					{
						paste(line, LEX_LITERAL);/// l
						flag_lit = true;
						flag_i = true;
					}

				}
				if (flag_lit && nai)
				{
					///��������� �� ���������
					entr.idxfirstLE = line;		///������ ������ ������ � ��
					entr.idtype = IT::L;
					strcpy(entr.fun, "");
					if (idtab.size > 0) 
					{
						///�� �� ����� - ������?
						for (int u = 0; u < idtab.size && nai; u++)
						{
							if (idtab.table[u].idtype == 4)	///���� ��� �������
							{
								if (flag_i == true)
								{
									if (atoi(word) == idtab.table[u].value.vint)
									{
										lextab.table[lextab.size - 1].idxTI = u;
										nai = false;///���� ������.
										povt_lit = true;
										flag_lit = false;
										flag_i = false;
									}
								}
								if (flag_s == true)
								{
									if (strcmp(word2, idtab.table[u].value.vstr.str) == 0)
									{
										lextab.table[lextab.size].idxTI = u;
										nai = false;
										povt_lit = true;
										flag_lit = false;
										flag_s = false;
									}
								}
							}
						}
					}
					///��� ���� - ������ ����� �������
					if (!povt_lit)
					{
						entr.id[0] = 'L';
						entr.id[1] = lit + 1;
						lit++;
						entr.id[2] = '\0';
						flag_lit = false;	///����: ������� ���������

						if (flag_s)
						{
							entr.iddatatype = IT::STR;				///���������� ��� ������
							strcpy(entr.value.vstr.str, word2);		///�������� �������� ������
							entr.value.vstr.len = strlen(word2);	///�����
							flag_s = false;							///����: ������� ���������
						}
						if (flag_i)
						{
							entr.iddatatype = IT::INT;
							entr.value.vint = atoi(word);
							flag_i = false;
						}
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, entr);
					}
					else
						povt_lit = false;
				}

				///������ �� ��������, ������������
				if ((ch == ' ' && word[0] == '\0'))
				{
					memset(word, '\0', strlen(word));
					continue;
				}

				///���� ����� �����, ��� �������� �� ��.
				if (word[0] == '\0')
					nai = true;

				///����� �� ��������, ��� �����. ��?
				if (!nai)
				{
					nai = proverka(word, fstidenf);	///abc
					if (nai)
						id = true;
				}
				///����� �������� ���������������
				if (nai && id)
				{
					nai = false;
					id = false;
					paste(line, LEX_ID);/// i
					lextab.table[lextab.size].idxTI = idtab.size;

					if (lextab.table[lextab.size - 2].lexema[0] != 'f')///��������� �� �������
					{
						if (strlen(word) < ID_MAXSIZE)
							strcpy(entr.id, word);
						else
						{
							for (int i = 0; i < 4; i++)
							{
								entr.id[i] = word[i];
							}
						}
						entr.idxfirstLE = line;	///������, �� ��� ��� �����
						strcpy(entr.fun, fun);	///�������� ������� ���������
					}
					else///���� �������
					{
						if (strcmp(word, "substr") == 0 || strcmp(word, "strlen") == 0)///���� ����� ����
						{
							strcpy(entr.fun, "External");
						}
						else
						{
							strcpy(entr.fun, fun);
						}
						strcpy(entr.functionname, word);
						strcpy(entr.id, "null");
						entr.idxfirstLE = line;
					}

					///�������� �� ����������
					if (idtab.size > 0)
						for (int u = 0; u < idtab.size && !nai; u++)
						{
							if (strcmp(fun, idtab.table[u].fun) == 0 || 
								strcmp(idtab.table[u].fun, "global") == 0 || 
								strcmp(idtab.table[u].fun, "External") == 0)
							{
								if (strcmp(idtab.table[u].id, "null") == 0 && 
									strcmp(idtab.table[u].functionname, word) == 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;

									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag_i = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag_s = false;
									}
									nai = false;///�������� ����
									povt_id = true;
								}
								if (strcmp(entr.id, idtab.table[u].id) == 0 &&	///���� ����� �� ��� ���� � ��
									strcmp(idtab.table[u].id, "null") != 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;
									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag_i = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag_s = false;
									}
									nai = false;///�������� ����
									povt_id = true;
								}
							}
						}
					///��� ��������������: V = 1, F = 2, P = 3, L = 4
					if (!povt_id)
					{
						entr.idtype = IT::V;///��� variable
						if (lextab.table[lextab.size - 2].lexema[0] == 'f')
						{
							entr.idtype = IT::F;///��� func
						}
						if ((lextab.table[lextab.size - 3].lexema[0] == '(' && lextab.table[lextab.size - 4].lexema[0] != 'v') || pflag)
						{
							entr.idtype = IT::P;///,���� ������, � �� ������� �� ��������
							pflag = true;
						}

						if (!nai)
						{
							if (flag_s)
							{
								entr.iddatatype = IT::STR;			///���� ������,�� ��� ������ ������
								strcpy(entr.value.vstr.str, "");	///�������� ������ ������
								entr.value.vstr.len = 0;			///����� ������ �� ����
								flag_s = false;						///���� �������
							}

							if (flag_i)
							{
								entr.iddatatype = IT::INT;
								entr.value.vint = 0;
								flag_i = false;
							}
						}
						IT::Add(idtab, entr);///� �������
					}
					else
						povt_id = false;
					nai = false;
				}
			}

			///�������� � ������ �������
			if (ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '=')
			{
				char word2[5];
				nai = false;
				word2[0] = ch;
				word2[1] = '\0';

				nai = proverka(word2, umn);///�������� �� *
				if (nai)
					paste(line, LEX_STAR);
				if (!nai)
				{
					nai = proverka(word2, ravno);///�������� �� =
					if (nai)
						paste(line, LEX_RAV);
				}
				if (!nai)
				{
					nai = proverka(word2, minus);///�������� �� -
					if (nai)
						paste(line, LEX_MINUS);
				}
				if (!nai)
				{
					nai = proverka(word2, plus);///�������� �� +
					if (nai)
						paste(line, LEX_PLUS);
				}
				if (!nai)
				{
					nai = proverka(word2, del);///�������� �� /
					if (nai)
						paste(line, LEX_DIRSLASH);
				}


			}
			
			///�������-����������
			if (ch == LEX_SEMICOLON || ch == LEX_LEFTHESIS ||
				ch == LEX_RIGHTHESIS || ch == LEX_LEFTBRACE ||
				ch == LEX_BRACELET || ch == LEX_COMMA)
			{
				nai = false;
				memset(word, '\0', strlen(word));
				word[0] = in.text[i];
				word[1] = '\0';
				nai = proverka(word, semicolon);///�������� �� ;
				if (nai)
					paste(line, LEX_SEMICOLON);
				if (!nai)
				{
					nai = proverka(word, leftbrace);///�������� �� {
					if (nai)
					{
						n = 1;
						paste(line, LEX_LEFTBRACE);
						///����� ��������� �-� ����� '}' � ���� ��� ���������
						while (n < idtab.size + 1 && strcmp(fun, "main") != 0)
						{
							if (idtab.table[idtab.size - n].idtype == 2)
							{
								funflag = true;
								break;
							}
							n++;
						}
						if (funflag)
						{
							strcpy(fun2, fun);
							strcpy(fun, idtab.table[idtab.size - n].functionname);
							funflag = false;
						}
					}
				}
				if (!nai)
				{
					nai = proverka(word, rightbrace);///�������� �� }
					if (nai)
					{
						paste(line, LEX_BRACELET);
						strcpy(fun, fun2);
					}
				}
				if (!nai)
				{
					nai = proverka(word, comma);///�������� �� ,
					if (nai)
						paste(line, LEX_COMMA);
				}
				if (!nai)
				{
					nai = proverka(word, leftthesis);///�������� �� (
					if (nai)
					{
						paste(line, LEX_LEFTHESIS);
						if (idtab.table[idtab.size - 1].idtype == 2 && strcmp(fun, "global") == 0)
						{
							strcpy(fun2, fun);
							strcpy(fun, idtab.table[idtab.size - 1].functionname);///�������� ��� ���������(��� ������� � �������)
							flagfun2 = true;
						}
					}
				}
				if (!nai)
				{
					nai = proverka(word, rightthesis);///�������� �� )
					if (nai)
					{
						paste(line, LEX_RIGHTHESIS);
						pflag = false;
						if (flagfun2)
						{
							strcpy(fun, fun2);
							flagfun2 = false;
						}

					}
				}
			}
			memset(word, '\0', strlen(word));
		}

		std::fstream file;
		file.open(parm.log);
		if (file.fail())
		{
			throw ERROR_THROW(112);	///������ ��� �������� ����� ���������
		}
		file << lextab.table[0].sn << ' ';


		for (int i = 0; i < lextab.size; i++)
		{
			if (lextab.table[i].lexema[0] == '|')
			{
				file << '\n';
				if (i != (lextab.size - 1))
				{
					file << lextab.table[i].sn << ' ';
				}
				continue;
			}
			file << lextab.table[i].lexema;

		}
		file << std::setw(15) << "|Name" << std::setw(2) << '|';
		file << std::setw(10) << "|Type" << std::setw(2) << '|';
		file << std::setw(15) << "|ID type" << std::setw(2) << '|';
		file << std::setw(15) << "|Line" << std::setw(2) << '|';
		file << std::setw(15) << "|Value" << std::setw(2) << '|';
		file << std::setw(12) << "|Length" << std::setw(2) << '|';
		file << std::setw(12) << "|Area" << std::setw(2) << '|' << '\n';
		for (int i = 0; i < idtab.size; i++)
		{
			if (strcmp(idtab.table[i].id, "null"))
				file << std::setw(15) << idtab.table[i].id << std::setw(2);
			else {
				file << std::setw(15) << idtab.table[i].functionname << std::setw(2);
			}
			if (idtab.table[i].iddatatype == IT::INT)
			{

				file << std::setw(15) << "integer" << std::setw(2);
			}
			if (idtab.table[i].iddatatype == IT::STR)
			{
				file << std::setw(15) << "string" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::F)
			{
				file << std::setw(15) << "function" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::P)
			{
				file << std::setw(15) << "parametr" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::L)
			{
				file << std::setw(15) << "literal" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::V)
			{
				file << std::setw(15) << "variable" << std::setw(2);
			}
			file << std::setw(15) << idtab.table[i].idxfirstLE << std::setw(2);

			if (idtab.table[i].iddatatype == IT::INT)
			{
				file << std::setw(15) << idtab.table[i].value.vint << std::setw(2) << std::setw(15) << " " << std::setw(2);
			}
			else
			{
				file << std::setw(15) << idtab.table[i].value.vstr.str << std::setw(2);
				file << std::setw(15) << idtab.table[i].value.vstr.len << std::setw(2);

			}
			if (strcmp(idtab.table[i].id, "strl") == 0)
				strcpy(idtab.table[i].fun, "External");
			file << std::setw(15) << idtab.table[i].fun << std::setw(2) << '\n';
		}
		file.close();
	}
};