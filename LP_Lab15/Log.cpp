#include "stdafx.h"
#include "Log.h"
#include <iostream>
#include <ctime>
namespace Log
{
	LOG getlog(wchar_t logfile[])
	{
		static std::ofstream stream(logfile);
		stream.seekp(0);
		LOG f;
		f.stream = &stream;
		wcscpy_s(f.logfile, logfile);
		f.stream->is_open();
		if (f.stream->fail())
		{
			throw ERROR_THROW(112);
		}
		return f;
	}
	void WriteLine(LOG log, char *c, ...)
	{
		log.stream->is_open();
		char** f;
		f = &c;
		char l[256] = "";
		while (*f != "")
		{
			strcat(l, *f);
			f = f + 1;
		}
		*(log.stream) << l << std::endl;
	}
	void WriteLine(LOG log, wchar_t *c, ...)
	{
		wchar_t** f = &c;
		char l[1024] = "";
		char* m = "";
		while (*f != L"")
		{
			wcstombs(m, *f, sizeof(f));
			strcat_s(l, sizeof(m), m);
			f = (f + 1);
		}
		*(log.stream) << l << std::endl;
	}
	void WriteLog(LOG log)
	{
		time_t rawtime;
		char buffer[80];
		time(&rawtime);
		char* format = "%d.%m.%Y %H:%M:%S";
		tm * timeinfo = localtime(&rawtime);
		strftime(buffer, 80, format, timeinfo);
		if (log.stream->fail() == 0)
		{
			log.stream->write("---��������--- ", sizeof("---��������--- "));
			log.stream->write("����: ", sizeof("����: "));
			*(log.stream) << buffer << "----------" << std::endl;
		}
	}
	void WriteParm(LOG log, Parm::PARM parm)
	{

		if (log.stream->fail() == 0)
		{
			char m[512] = "";
			log.stream->write("---���������---", sizeof("---���������---"));
			(*log.stream) << std::endl;
			wcstombs(m, parm.in, sizeof(parm.in));
			*(log.stream) << "-in: " << m << std::endl;
			wcstombs(m, parm.out, sizeof(parm.out));
			*(log.stream) << "-out: " << m << std::endl;
			wcstombs(m, parm.log, sizeof(parm.log));
			*(log.stream) << "=log: " << m << std::endl;
		}
		else
		{
			std::cout << "in: " << parm.in << std::endl;
			std::cout << "out:" << parm.out << std::endl;
			std::cout << "log: " << parm.log << std::endl;
		}
	}
	void WriteIn(LOG log, In::IN in)
	{
		if (log.stream->fail() == 0)
		{
			log.stream->write("---�������� ���������---", sizeof("---�������� ���������---"));
			(*log.stream) << std::endl;
			log.stream->write("���������� ��������:", sizeof("���������� ��������:"));
			*(log.stream) << in.size << std::endl;
			log.stream->write("����������������: ", sizeof("����������������: "));
			*(log.stream) << in.ignor << std::endl;
			log.stream->write("���������� �����: ", sizeof("���������� �����: "));
			*(log.stream) << in.lines << std::endl;
		}
		else
		{
			std::cout << "���������� ��������: " << in.size << std::endl;
			std::cout << "����������������:" << in.ignor << std::endl;
			std::cout << "���������� �����: " << in.lines << std::endl;
		}
	}
	void WriteError(LOG log, Error::ERROR error)
	{
		if (log.stream->fail() == 0)
		{
			*(log.stream) << error.id << " " << error.message << " ������ " << error.inext.line << " ������� " << error.inext.col;
			*(log.stream) << std::endl;
		}
		else
		{
			std::cout << error.id << " " << error.message << " " << "������" << error.inext.line << " �������" << error.inext.col << std::endl;
		}
	}
	void Close(LOG log)
	{
		log.stream->close();
	}
};