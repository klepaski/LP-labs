#pragma once

namespace Call
{
	int _cdecl cdevl(int &aa, int &bb, int &cc);//3 �� ������ (� ���� ������-������, �)
	int _stdcall cstd(int &aa, int b, int c);	//1 �� ������, 2 �� �������� (� ���� ������-������, �)
	int _fastcall cfst(int a, int b, int c);	//3 �� �������� (2 ����. � �������, �)
}