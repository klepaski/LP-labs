#pragma once

namespace Varparm
{
	int ivarparm(int n, ...);		//������������ ����������, ������� �� �������
									//n - ���-�� ������������� ����������

	int  svarparm(short n, ...);

	double fvarparm(float f, ...);	//����� ���������� � ������� �� �������������
									//���������� ���-�� ����������
									//����.���. - ���� ����� ���� float (���. �����. ������)

	double dvarparm(double d, ...);
}