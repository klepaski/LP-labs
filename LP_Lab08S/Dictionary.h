#pragma once

#include <cstring>
#define DICTNAMEMAXSIZE		20		//максимальный размер имени словар€
#define DICTMAXSIZE			100		//макс.Ємкость словар€
#define ENTRYNAMEMAXSIZE	30		//макс.длина имени в словаре

#define THROW01 "Create: превышен размер имени словар€"
#define THROW02	"Create: превышен размер максимальной Ємкости словар€"
#define THROW03 "AddEntry: переполнение словар€"
#define THROW04	"AddEntry: дублирование индентификатора"
#define THROW05	"GetEntry: не найден элемент"
#define THROW06	"DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"

namespace Dictionary {	///пространство имЄн - область, в кот. опред. идентификторы (имена типов, ф-ций, переменных)
	struct Entry {									///элемент словар€
		int id;									//идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE];			//символьна€ информаци€
	};
	struct Instance {								///экземпл€р словар€
		char name[DICTNAMEMAXSIZE];				//наименование словар€
		int maxsize;							//макс.	Ємкость словар€
		int size;								//текущий размер словар€ < DICTNAMEMAXSIZE
		Entry *dictionary;						//массив эл-тов словар€
	};
	Instance Create(								///создать словарь
		const char name[DICTNAMEMAXSIZE],		//им€ словар€
		int size								//Ємкоть словар€ < DICTNAMEMAXSIZE
	);
	void AddEnrty(									///добавить элемент словар€
		Instance& inst,							//экземпл€р словар€
		Entry ed								//элемент словар€
	);
	void DelEntry(									///удалить элемент словар€
		Instance& inst,							//экземпл€р словар€
		int id									//идентификатор удал€емого элемента(уникальный)
	);
	void UpdEntry(									///изменить элемент словар€
		Instance& inst,							//экземпл€р словар€
		int id,									//идентификатор замен€емого элемента
		Entry new_ed							//новый элемент словар€	
	);
	Entry GetEntr(									///получить элемент словар€		
		Instance inst,							//экземпл€р словар€
		int id									//идентификатор получаемого элемента
	);
	void Print(Instance d);							///печать словар€
	void Delete(Instance& d);						///удалить словарь
}