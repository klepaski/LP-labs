#include "stdafx.h"
#include "Call.h"

namespace Call
{
	int _cdecl cdevl(int &aa, int &bb, int &cc)
	{
		return aa*bb*cc;
	}

	int _stdcall cstd(int &aa, int b, int c)
	{
		return aa*b*c;
	}

	int _fastcall cfst(int a, int b, int c)
	{
		return a*b*c;
	}
}