//Реализуйте функции сериализации и десериализации двусвязного списка в бинарном формате в файл.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ostream>
#include "List.h"

int main()
{
	List* list = new List();


	std::cout << "\n\nPlease, enter the number of strings for List\n";
	int nums;
	std::cin >> nums;
	std::cout << "Please, enter a strings\n";
	for (int i = 0; i < nums; i++)
	{
		std::string tmp;
		std::cin >> tmp;
		list->Add(tmp);

	}


	FILE * ptrFile = fopen("file.bin", "wb");
	list->Serialize(ptrFile);
	fclose(ptrFile);
	list->ReleseNodes(); delete list;


	ptrFile = fopen("file.bin", "rb");
	List *list2 = new List();
	list2->Deserialize(ptrFile);
	std::cout << "\n\n Data from file: \n";
	for (int i = 0; i < list2->Count(); i++)
	{
		std::cout << list2->operator[](i)->data << "\n";
	}

	fclose(ptrFile);
	list2->ReleseNodes(); delete list2;

	system("pause");
	return 0;
}
