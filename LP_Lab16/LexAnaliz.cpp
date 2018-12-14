#include "stdafx.h"
#include "Log.h"
#include "MFST.h"
#include "GRB.h"
#include "Check.h"
#include "Parm.h"
#include "FST.h"
#include "LT.h"
#include "IT.h"
#include <iostream>
#include <iomanip>
#include <stack>
#define EXP1 20
#define EXP2 50
#define EXP3 73
#define MFST_TRACE_START std::cout<<std::setw(4)<<std::left<<"Шаг"<<":"\
						 <<std::setw(20)<<std::left<<"Правило"\
						 <<std::setw(30)<<std::left<<"Входная лента"\
						 <<std::setw(20)<<std::left<<"Стек"\
						 <<std::endl;
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
//string
FST::FST typestring("", 7,
	FST::NODE(1, FST::RELATION('s', 1)),
	FST::NODE(1, FST::RELATION('t', 2)),
	FST::NODE(1, FST::RELATION('r', 3)),
	FST::NODE(1, FST::RELATION('i', 4)),
	FST::NODE(1, FST::RELATION('n', 5)),
	FST::NODE(1, FST::RELATION('g', 6)),
	FST::NODE()
);
//function
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
//declare
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
//return
FST::FST streturn("", 7,
	FST::NODE(1, FST::RELATION('r', 1)),
	FST::NODE(1, FST::RELATION('e', 2)),
	FST::NODE(1, FST::RELATION('t', 3)),
	FST::NODE(1, FST::RELATION('u', 4)),
	FST::NODE(1, FST::RELATION('r', 5)),
	FST::NODE(1, FST::RELATION('n', 6)),
	FST::NODE()
);
//main
FST::FST strmain("", 5,
	FST::NODE(1, FST::RELATION('m', 1)),
	FST::NODE(1, FST::RELATION('a', 2)),
	FST::NODE(1, FST::RELATION('i', 3)),
	FST::NODE(1, FST::RELATION('n', 4)),
	FST::NODE()
);
//print
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
	FST::NODE(20, FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
		FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
		FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
		FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
		FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
		FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
		FST::RELATION('8', 1), FST::RELATION('9', 1)),
	FST::NODE()
);
FST::FST fstidenf("", 2,
	FST::NODE(54, FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
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
	void zapol(int line, char m)
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
	bool PolishNotation(int pos, LT::LexTable &lextb, IT::IdTable &idtb)
	{
		int n = 0;
		char f = ' ';
		std::stack <char> steck;
		bool flagfunction = false;
		char string[256] = "";
		int length = 0;
		int lengthstr = 0;
		char str[256] = "";
		while (lextb.table[pos + n].lexema[0] != ';')
		{
			if (lextb.table[pos + n].lexema[0] == 'i' || lextb.table[pos + n].lexema[0] == 'v'
				|| lextb.table[pos + n].lexema[0] == '(' || lextb.table[pos + n].lexema[0] == ')'
				|| lextb.table[pos + n].lexema[0] == ',' || lextb.table[pos + n].lexema[0] == 'l')
			{
				if (lextb.table[pos + n].lexema[0] == '(')
				{
					steck.push(lextb.table[pos + n].lexema[0]);
				}
				if (lextb.table[pos + n].lexema[0] == 'v')
				{
					if (steck.empty())
					{
						steck.push(idtb.table[lextb.table[pos + n].idxTI].operation[0]);
					}
					else
					{
						if (steck.top() == '(')
						{
							steck.push(idtb.table[lextb.table[pos + n].idxTI].operation[0]);
						}
						else
						{
							while (!steck.empty())
							{
								if (steck.top() != '(')
								{
									str[lengthstr] = steck.top();
									lengthstr++;
									steck.pop();
									if (idtb.table[lextb.table[pos + n].idxTI].operation[0] == '+' || idtb.table[lextb.table[pos + n].idxTI].operation[0] == '-')
									{
										string[length] = str[lengthstr - 1];
										length++;
										str[lengthstr - 1] = ' ';
										lengthstr--;
									}
									if (idtb.table[lextb.table[pos + n].idxTI].operation[0] == '/' || idtb.table[lextb.table[pos + n].idxTI].operation[0] == '*')
									{
										if (str[lengthstr - 1] == '/' || str[lengthstr - 1] == '*')
										{
											string[length] = str[lengthstr - 1];
											length++;
											str[lengthstr - 1] = ' ';
											lengthstr--;
										}
									}
								}
								else
									break;
							}
							for (int i = 0; i < lengthstr; i++)
							{
								steck.push(str[lengthstr - 1 - i]);
							}
							strcpy(str, "");
							lengthstr = 0;
							steck.push(idtb.table[lextb.table[pos + n].idxTI].operation[0]);
						}
					}
					/*
					steck.push(']');
					steck.push((idtb.table[lextb.table[pos + n].idxTI].operation[0]));
					steck.push('[');
					steck.push(lextb.table[pos + n].lexema[0]);
					*/
				}
				if (lextb.table[pos + n].lexema[0] == 'i' || lextb.table[pos + n].lexema[0] == 'l')
				{
					if (idtb.table[lextb.table[pos + n].idxTI].idtype == 2)
					{
						steck.push('@');
						flagfunction = true;
					}
					else
					{
						for (int i = 0; i < strlen(idtb.table[lextb.table[pos + n].idxTI].id); i++)
						{
							string[length] = idtb.table[lextb.table[pos + n].idxTI].id[i];
							length++;
						}
						/*
						strcpy(str, "");
						string[length] = lextb.table[pos + n].lexema[0];
						length++;
						string[length] = '{';
						length++;
						strcat(string,_itoa(lextb.table[pos + n].idxTI,str,10));
						length=length+strlen(str);
						string[length] = '}';
						length++;
						*/
					}
				}
				if (lextb.table[pos + n].lexema[0] == ')' && !flagfunction)
				{
					do
					{
						f = steck.top();
						steck.pop();
						if (f != '(')
						{
							string[length] = f;
							length++;
						}
					} while (f != '(');
				}
				if (lextb.table[pos + n].lexema[0] == ')' && flagfunction)
				{
					flagfunction = false;
					do
					{
						f = steck.top();
						steck.pop();
						if (f != '(')
						{
							string[length] = f;
							length++;
						}
					} while (f != '@');
				}
			}
			else
				return false;
			n++;
		}
		while (!steck.empty())
		{
			string[length] = steck.top();
			steck.pop();
			length++;
		}
		for (int i = 0; i < length; i++)
		{
			lextb.table[pos + i].lexema[0] = string[i];
		}
		for (int i = 0; i < (n - length); i++)
		{
			lextb.table[i + pos + length].lexema[0] = '\0';
		}
		return true;
	}
	void Leksika(Parm::PARM parm, In::IN in)
	{
		char word[255] = "";
		char word2[255] = "";
		bool flagfun2 = false;
		int m = 0;//счетчик символов
		int line = 1;//счетчик строк 
		bool nai = false;// флаг 
		bool id1 = false;//повторение идентификатора
		char sim;
		bool flag = false;//string 
		bool flag1 = false;//int
		bool pflag = false;
		bool po = false;
		bool id = false;
		short lit = 0;
		bool lt = false;
		int n = 0;
		IT::Entry entr;
		bool funflag = false;
		short kavich = 0;
		char fun[10] = "global";
		char fun2[10] = "global";
		bool lt1 = false;//повторение литерала
		for (int i = 0; i < in.size; i++)
		{
			sim = in.text[i];
			nai = false;
			if (sim == IN_CODE_ENDL)
			{
				line++;
				continue;
			}
			if (sim == '\'')
			{
				kavich++;
				if (kavich == 2)
					kavich = 0;
			}
			if (kavich == 1)
			{
				word[m] = sim;
				m++;
				continue;
			}

			//запись входного слова на проверку
			if (sim != ' ' && sim != ';' && sim != '-' && sim != '+' && sim != '/' && sim != '*' && sim != '\''
				&& sim != ','&&sim != ')' && sim != '(' && sim != '}' && sim != '{' && sim != IN_CODE_ENDL && sim != '=')
			{
				word[m] = sim;
				m++;
				continue;
			}
			//проверка на ключевые слова
			else
			{
				word[m] = '\0';
				m = 0;

				if (sim == IN_CODE_ENDL)
				{
					line++;
					continue;
				}
				nai = proverka(word, typestring);
				if (nai)//является ключевым словом string
				{
					zapol(line, LEX_STRING);
					flag = true;
				}
				if (!nai)
				{
					nai = proverka(word, typeint);
					if (nai)//является ключевым словом integer
					{
						flag1 = true;
						zapol(line, LEX_INTEGER);
					}
				}

				if (!nai)//ключевое слово function
				{
					nai = proverka(word, typefunction);
					if (nai)
						zapol(line, LEX_FUNCTION);
				}
				if (!nai)//ключевое слово declare
				{
					nai = proverka(word, strdeclare);
					if (nai)
						zapol(line, LEX_DECLARE);
				}
				if (!nai)//ключевое слово return
				{
					nai = proverka(word, streturn);
					if (nai)
						zapol(line, LEX_RETURN);
				}
				if (!nai)//ключевое слово main
				{
					nai = proverka(word, strmain);
					if (nai)
					{
						zapol(line, LEX_MAINFUNC);
						strcpy(fun, "main");
						strcpy(fun2, "global");
					}

				}
				if (!nai)//ключевое слово print
				{
					nai = proverka(word, strprint);
					if (nai)
						zapol(line, LEX_PRINT);
				}

				//Строковый литерал?
				if (word[0] == '\'')//строковый литерал?
				{
					zapol(line, LEX_LITERAL);
					for (int i = 0; i < strlen(word); i++)
						word2[i] = word[i + 1];
					word2[strlen(word)] = '\0';
					nai = true;
					lt = true;
					flag = true;
				}
				//Целочисленный литерал?
				if (!nai)
				{
					nai = proverka(word, Literal);
					if (nai)
					{
						zapol(line, LEX_LITERAL);
						lt = true;
						flag1 = true;
					}

				}
				if (lt && nai)
				{
					//заполняем таблицу идентификаторов литералом
					entr.idxfirstLE = line;
					entr.idtype = IT::L;
					strcpy(entr.fun, "");
					if (idtab.size > 0)
					{
						for (int u = 0; u < idtab.size && nai; u++)
						{
							if (idtab.table[u].idtype == 4)
							{
								if (flag1 == true)
								{
									if (atoi(word) == idtab.table[u].value.vint)
									{
										lextab.table[lextab.size - 1].idxTI = u;
										nai = false;
										lt1 = true;
										lt = false;
										flag1 = false;
									}
								}
								if (flag == true)
								{
									if (strcmp(word2, idtab.table[u].value.vstr.str) == 0)
									{
										lextab.table[lextab.size].idxTI = u;
										nai = false;
										lt1 = true;
										lt = false;
										flag = false;
									}
								}
							}
						}
					}
					if (!lt1)
					{
						lit++;
						strcpy(entr.operation, "$");
						entr.id[0] = 'L';
						char o2 = (char)lit % 10;
						entr.id[2] = o2;
						if (lit - (lit % 10) <= 0)
						{
							entr.id[1] = '0';
						}
						else
						{
							entr.id[1] = lit - (lit % 10);
						}
						entr.id[3] = '\0';
						lt = false;
						if (flag)
						{
							entr.iddatatype = IT::STR;
							strcpy(entr.value.vstr.str, word2);
							entr.value.vstr.len = strlen(word2);
							flag = false;
						}
						if (flag1)
						{
							entr.iddatatype = IT::INT;
							entr.value.vint = atoi(word);
							flag1 = false;
						}
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, entr);
					}
					else
						lt1 = false;
				}
				//Ничего не содержит, игнорируется
				if ((sim == ' ' && word[0] == '\0'))//если пробел
				{
					memset(word, '\0', strlen(word));
					continue;
				}

				//если слово ничего не содержит, не проверяется на возможность идентификатора
				if (word[0] == '\0')
					nai = true;

				//слово не является ключевым, проверяем на возможность идентификатора
				if (!nai)
				{

					nai = proverka(word, fstidenf);
					if (nai)
						id = true;
				}
				//слово является идентификатором
				if (nai && id)//слово является идентификатором
				{
					nai = false;
					id = false;
					zapol(line, LEX_ID);
					lextab.table[lextab.size].idxTI = idtab.size;
					//заполняем идентификатор для дальнейшего "заполнения" значением
					if (lextab.table[lextab.size - 2].lexema[0] != 'f')
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
						entr.idxfirstLE = line;
						strcpy(entr.fun, fun);
					}
					else
					{
						if (strcmp(word, "substr") == 0 || strcmp(word, "strlen") == 0)
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

					//проверка на "вторичное" использование"
					if (idtab.size > 0)
						for (int u = 0; u < idtab.size && !nai; u++)
						{
							if (strcmp(fun, idtab.table[u].fun) == 0 || strcmp(idtab.table[u].fun, "global") == 0 || strcmp(idtab.table[u].fun, "External") == 0)
							{
								if (strcmp(idtab.table[u].id, "null") == 0 && strcmp(idtab.table[u].functionname, word) == 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;
									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag1 = false;
									}
									nai = false;
									id1 = true;
								}
								if (strcmp(entr.id, idtab.table[u].id) == 0 && strcmp(idtab.table[u].id, "null") != 0)
								{
									lextab.table[lextab.size - 1].idxTI = u;
									if (idtab.table[u].iddatatype == IT::INT)
									{
										flag = false;
									}
									if (idtab.table[u].iddatatype == IT::STR)
									{
										flag1 = false;
									}
									nai = false;
									id1 = true;
								}
							}
						}
					//тип идентификатора: V = 1, F = 2, P = 3, L = 4
					if (!id1)
					{
						entr.idtype = IT::V;
						strcpy(entr.operation, "$");
						if (lextab.table[lextab.size - 2].lexema[0] == 'f')
						{
							entr.idtype = IT::F;
						}
						if ((lextab.table[lextab.size - 3].lexema[0] == '(' && lextab.table[lextab.size - 4].lexema[0] != 'v') || pflag)
						{
							entr.idtype = IT::P;
							pflag = true;
						}
						if (flag)
						{
							entr.iddatatype = IT::STR;
							strcpy(entr.value.vstr.str, "");
							entr.value.vstr.len = 0;
							flag = false;
						}

						if (flag1)
						{
							entr.iddatatype = IT::INT;
							entr.value.vint = 0;
							flag1 = false;
						}
						IT::Add(idtab, entr);
					}
					else
						id1 = false;
					nai = false;
				}
			}
			//операции с целыми числами
			if (sim == '+' || sim == '*' || sim == '-' || sim == '/' || sim == '=')
			{
				char word2[5];
				nai = false;
				word2[0] = sim;
				word2[1] = '\0';
				strcpy(entr.operation, word2);
				strcpy(entr.id, "oper");
				strcpy(entr.fun, "operation");
				nai = proverka(word2, umn);
				if (nai)
				{
					zapol(line, LEX_STAR);
				}
				if (!nai)
				{
					nai = proverka(word2, ravno);
					if (nai)
						zapol(line, LEX_RAV);
				}
				if (!nai)
				{
					nai = proverka(word2, minus);
					if (nai)
					{
						zapol(line, LEX_MINUS);

					}
				}
				if (!nai)
				{
					nai = proverka(word2, plus);
					if (nai)
					{
						zapol(line, LEX_PLUS);
					}
				}
				if (!nai)
				{
					nai = proverka(word2, del);
					if (nai)
					{
						zapol(line, LEX_DIRSLASH);
					}
				}
				for (int u = 0; u < idtab.size && !po; u++)
				{
					if (strcmp(entr.operation, idtab.table[u].operation) == 0)
					{
						lextab.table[lextab.size - 1].idxTI = u;
						po = true;
					}
				}
				if (!po)
				{
					IT::Add(idtab, entr);
					lextab.table[lextab.size - 1].idxTI = idtab.size - 1;
				}
				po = false;
			}
			//символы-сепараторы
			if (sim == LEX_SEMICOLON || sim == LEX_LEFTHESIS ||
				sim == LEX_RIGHTHESIS || sim == LEX_LEFTBRACE ||
				sim == LEX_BRACELET || sim == LEX_COMMA)
			{
				nai = false;
				memset(word, '\0', strlen(word));
				word[0] = in.text[i];
				word[1] = '\0';
				nai = proverka(word, semicolon);
				if (nai)
					zapol(line, LEX_SEMICOLON);
				if (!nai)
				{
					nai = proverka(word, leftbrace);
					if (nai)
					{
						n = 1;
						zapol(line, LEX_LEFTBRACE);
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
					nai = proverka(word, rightbrace);
					if (nai)
					{
						zapol(line, LEX_BRACELET);
						strcpy(fun, fun2);
					}
				}
				if (!nai)
				{
					nai = proverka(word, comma);
					if (nai)
						zapol(line, LEX_COMMA);
				}
				if (!nai)
				{
					nai = proverka(word, leftthesis);
					if (nai)
					{
						zapol(line, LEX_LEFTHESIS);
						if (idtab.table[idtab.size - 1].idtype == 2 && strcmp(fun, "global") == 0)
						{
							strcpy(fun2, fun);
							strcpy(fun, idtab.table[idtab.size - 1].functionname);
							flagfun2 = true;
						}
					}
				}
				if (!nai)
				{
					nai = proverka(word, rightthesis);
					if (nai)
					{
						zapol(line, LEX_RIGHTHESIS);
						pflag = false;
						if (flagfun2)
						{
							strcpy(fun, fun2);
							flagfun2 = false;
						}

					}
				}
			}
			//скидываем все что было в токене 
			memset(word, '\0', strlen(word));
		}
		/*
		if (PolishNotation(EXP1, lextab, idtab))
			std::cout << "Польская запись построена"<<std::endl;
		else
			std::cout << "Польская запись не построена" << std::endl;
		if (PolishNotation(EXP2, lextab, idtab))
			std::cout << "Польская запись построена" << std::endl;
		else
			std::cout << "Польская запись не построена" << std::endl;
		if (PolishNotation(EXP3, lextab, idtab))
			std::cout << "Польская запись построена" << std::endl;
		else
			std::cout << "Польская запись не построена" << std::endl;
		*/
		std::fstream file;
		file.open(parm.log);
		if (file.fail())
		{
			throw ERROR_THROW(112);
		}
		file << lextab.table[0].sn << ' ';
		//запись токенов для наглядности
		for (int i = 0; i < lextab.size; i++)
		{
			if (lextab.table[i].lexema[0] != '\0')
			{
				if (i != 0)
				{
					if (lextab.table[i - 1].sn != lextab.table[i].sn)
					{
						file << '\n';
					}
				}
				file << lextab.table[i].lexema[0];
			}
		}
		file << std::setw(13) << "Name" << std::setw(2) << '|';
		file << std::setw(16) << "Type" << std::setw(2) << '|';
		file << std::setw(16) << "Typeid" << std::setw(2) << '|';
		file << std::setw(16) << "Line" << std::setw(2) << '|';
		file << std::setw(16) << "Value" << std::setw(2) << '|';
		file << std::setw(16) << "Length" << std::setw(2) << '|';
		file << std::setw(16) << "Area" << std::setw(2) << '|' << '\n';
		for (int i = 0; i < idtab.size; i++)
		{
			if (strcmp(entr.operation, "$") == 0)
			{
				if (strcmp(idtab.table[i].id, "null"))
					file << std::setw(13) << idtab.table[i].id << std::setw(2) << '|';
				else
					file << std::setw(13) << idtab.table[i].functionname << std::setw(2) << '|';
				if (idtab.table[i].iddatatype == IT::INT)
				{
					file << std::setw(16) << "integer" << std::setw(2) << '|';
				}
				if (idtab.table[i].iddatatype == IT::STR)
				{
					file << std::setw(16) << "string" << std::setw(2) << '|';
				}
				if (idtab.table[i].idtype == IT::F)
				{
					file << std::setw(16) << "function" << std::setw(2) << '|';
				}
				if (idtab.table[i].idtype == IT::P)
				{
					file << std::setw(16) << "parameter" << std::setw(2) << '|';
				}
				if (idtab.table[i].idtype == IT::L)
				{
					file << std::setw(16) << "literal" << std::setw(2) << '|';
				}
				if (idtab.table[i].idtype == IT::V)
				{
					file << std::setw(16) << "variable" << std::setw(2) << '|';
				}
				file << std::setw(16) << idtab.table[i].idxfirstLE << std::setw(2) << '|';
				if (idtab.table[i].iddatatype == IT::INT)
				{
					file << std::setw(16) << idtab.table[i].value.vint << std::setw(2) << '|' << std::setw(16) << " " << std::setw(2) << '|';
				}
				else
				{
					file << std::setw(16) << idtab.table[i].value.vstr.str << std::setw(2) << "|";
					file << std::setw(16) << idtab.table[i].value.vstr.len << std::setw(2) << '|';

				}
				file << std::setw(16) << idtab.table[i].fun << std::setw(2) << '|' << '\n';
			}
		}
		file.close();
		MFST_TRACE_START
			MFST::Mfst mfst(lextab, GRB::getGreibach());
		mfst.start();
		mfst.savededucation();
		mfst.printrules();
	}
};