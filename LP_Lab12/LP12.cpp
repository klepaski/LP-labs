// LP12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FST.h"
#include <iostream>


using FST::myFunc;

int main()
{
	//m(b)+(s+w+h);b+)*b+r;
	char myString1[] = "mbbr;";
	myFunc(myString1);

	char myString2[] = "mbbbs;bbr;";
	myFunc(myString2);

	char myString3[] = "mbs;bbbr;";
	myFunc(myString3);

	char myString4[] = "mbbbbbr;";
	myFunc(myString4);

	char myString5[] = "mbh;bbbr;";
	myFunc(myString5);

	char myString6[] = "mbw;bbr;";
	myFunc(myString6);

	char myString7[] = "mbbbs;bbr;";
	myFunc(myString7);


	std::cout << "-------------------" << std::endl;


	char myStringWithError1[] = "mbr;";
	myFunc(myStringWithError1);

	char myStringWithError2[] = "mbbabbbbr;";
	myFunc(myStringWithError2);

	char myStringWithError3[] = "af;";
	myFunc(myStringWithError3);

	char myStringWithError4[] = "a;bbbec;f";
	myFunc(myStringWithError4);


	system("pause");
	return 0;
}
