#include "stdafx.h"
#include "Dictionary.h"
#include <iostream>

using namespace Dictionary;

Instance Dictionary::Create(const char name[DICTNAMEMAXSIZE], int size)   //создать экземпляр словаря
{
	if (strlen(name) > DICTNAMEMAXSIZE) throw THROW01;
	if (size > DICTMAXSIZE) throw THROW02;
	Instance *dict = new Instance;
	dict->dictionary = new Entry[size];
	dict->size = strlen(name);
	strcpy_s(dict->name, name);
	dict->maxsize = size;
	return *dict;
}

void Dictionary::AddEnrty(Instance& inst, Entry ed) {  //добавить элемент словаря
	if (ed.id > inst.maxsize) throw THROW03;
	if (inst.dictionary[ed.id - 1].id == ed.id) throw THROW04;
	inst.dictionary[ed.id - 1] = ed;
}




void Dictionary::DelEntry(Instance & inst, int id)     //удалить элемент словаря
{
	int j = 0;
	for (int i = 0; i < inst.maxsize; i++)
	{
		if (inst.dictionary[i].id == id)
		{
			for (j = i; j < inst.maxsize; j++)
				inst.dictionary[j] = inst.dictionary[j + 1];
			inst.maxsize--;
			break;
		}
	}
	if (j == 0) throw THROW06;
}

void Dictionary::UpdEntry(Instance& inst, int id, Entry new_ed) {  //изменить элемент словаря
	if (inst.dictionary[id - 1].id == new_ed.id) throw THROW08;
	if (id > inst.maxsize) throw THROW07;
	inst.dictionary[id - 1] = new_ed;
}

Entry Dictionary::GetEntr(Instance inst, int id)  //получить элемент словаря
{
	if (id > inst.maxsize) throw THROW05;
	Entry entVal = inst.dictionary[id - 1];
	return entVal;
}

void Dictionary::Print(Instance d) {		//печать
	std::cout << "---------------------------" << std::endl;
	std::cout << "Название словаря: " << d.name << std::endl;
	std::cout << "Элементы словаря: " << std::endl;
	for (int i = 0; i < d.maxsize; ++i) {
		std::cout << "Id: " << d.dictionary[i].id << " Название: " << d.dictionary[i].name << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
}

void Dictionary::Delete(Instance& d) {   //удаление
	delete d.dictionary;
	std::cout << "COMPLETE" << std::endl;
}
