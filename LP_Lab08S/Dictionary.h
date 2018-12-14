#pragma once

#include <cstring>
#define DICTNAMEMAXSIZE		20		//������������ ������ ����� �������
#define DICTMAXSIZE			100		//����.������� �������
#define ENTRYNAMEMAXSIZE	30		//����.����� ����� � �������

#define THROW01 "Create: �������� ������ ����� �������"
#define THROW02	"Create: �������� ������ ������������ ������� �������"
#define THROW03 "AddEntry: ������������ �������"
#define THROW04	"AddEntry: ������������ ���������������"
#define THROW05	"GetEntry: �� ������ �������"
#define THROW06	"DelEntry: �� ������ �������"
#define THROW07 "UpdEntry: �� ������ �������"
#define THROW08 "UpdEntry: ������������ ��������������"

namespace Dictionary {	///������������ ��� - �������, � ���. �����. ������������� (����� �����, �-���, ����������)
	struct Entry {									///������� �������
		int id;									//������������� (����������)
		char name[ENTRYNAMEMAXSIZE];			//���������� ����������
	};
	struct Instance {								///��������� �������
		char name[DICTNAMEMAXSIZE];				//������������ �������
		int maxsize;							//����.	������� �������
		int size;								//������� ������ ������� < DICTNAMEMAXSIZE
		Entry *dictionary;						//������ ��-��� �������
	};
	Instance Create(								///������� �������
		const char name[DICTNAMEMAXSIZE],		//��� �������
		int size								//������ ������� < DICTNAMEMAXSIZE
	);
	void AddEnrty(									///�������� ������� �������
		Instance& inst,							//��������� �������
		Entry ed								//������� �������
	);
	void DelEntry(									///������� ������� �������
		Instance& inst,							//��������� �������
		int id									//������������� ���������� ��������(����������)
	);
	void UpdEntry(									///�������� ������� �������
		Instance& inst,							//��������� �������
		int id,									//������������� ����������� ��������
		Entry new_ed							//����� ������� �������	
	);
	Entry GetEntr(									///�������� ������� �������		
		Instance inst,							//��������� �������
		int id									//������������� ����������� ��������
	);
	void Print(Instance d);							///������ �������
	void Delete(Instance& d);						///������� �������
}