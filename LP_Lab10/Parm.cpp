#include "stdafx.h"
#include <iostream>
#include "Parm.h"
#include "Error.h"

namespace Parm {
	PARM getparm(int argc, _TCHAR* argv[])
	{
		if (argc > 1)
		{
			if (wcslen(argv[1]) > PARM_MAX_SIZE)
			{
				throw ERROR_THROW(104);	///превышена длина вводного параметра
			}
			else if (!wcsstr(argv[1], PARM_IN))	///ищет подстроку
			{
				throw ERROR_THROW(100);	///параметр -in должен быть задан
			}
		}
		PARM Parm;
		switch (argc)
		{
		case 2: {
			wcsncpy_s(Parm.in, argv[1] + 4, wcslen(argv[1]) - wcslen(PARM_IN));

			wcscpy_s(Parm.out, Parm.in);
			wcscat_s(Parm.out, PARM_OUT_DEFAULT_EXT);

			wcscpy_s(Parm.log, Parm.in);
			wcscat_s(Parm.log, PARM_LOG_DEFAULT_EXT);
			break;
		}
		case 3: {
			if (wcslen(argv[2]) > PARM_MAX_SIZE)
			{
				throw ERROR_THROW(104);
			}
			wcsncpy_s(Parm.in, argv[1] + 4, wcslen(argv[1]) - wcslen(PARM_IN));
			if (!wcsstr(argv[2], PARM_OUT))   /// dodelat
			{
				wcsncpy_s(Parm.out, argv[2] + 5, wcslen(argv[2]) - wcslen(PARM_OUT));
				wcscpy_s(Parm.log, Parm.in);
				wcscat_s(Parm.log, PARM_LOG_DEFAULT_EXT);
			}
			else
			{
				wcsncpy_s(Parm.log, argv[3] + 5, wcslen(argv[3]) - wcslen(PARM_LOG));
				wcscpy_s(Parm.out, Parm.in);
				wcscat_s(Parm.out, PARM_LOG_DEFAULT_EXT);
			}
			break;
		}
		case 4: {
			wcsncpy_s(Parm.in, argv[1] + 4, wcslen(argv[1]) - wcslen(PARM_IN));
			wcsncpy_s(Parm.out, argv[2] + 5, wcslen(argv[2]) - wcslen(PARM_OUT));
			wcsncpy_s(Parm.log, argv[3] + 5, wcslen(argv[3]) - wcslen(PARM_LOG));
			break;
		}
		case 1: throw ERROR_THROW(100); break; 	///параметр -in должен быть задан
		}
		return Parm;
	}
}