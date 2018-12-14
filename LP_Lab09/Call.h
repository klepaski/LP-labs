#pragma once

namespace Call
{
	int _cdecl cdevl(int &aa, int &bb, int &cc);//3 по ссылке (в стек справа-налево, щ)
	int _stdcall cstd(int &aa, int b, int c);	//1 по ссылке, 2 по значению (в стек справа-налево, м)
	int _fastcall cfst(int a, int b, int c);	//3 по значению (2 посл. в регистр, м)
}