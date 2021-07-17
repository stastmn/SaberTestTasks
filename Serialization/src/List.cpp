#include "List.h"
#include <assert.h>

//Write a string "str" into stream "os"
void Write(std::string& str, FILE* file)
{
	// adding one to .size() because the string doesn't count '\0'
	uint32_t sizeOfString = static_cast<uint32_t>(str.size() + 1);
	fwrite(reinterpret_cast<char*>(&sizeOfString), sizeof(uint32_t), 1, file);

	if (sizeOfString > 0) fwrite(str.c_str(), sizeof(char), sizeOfString, file);

}

std::string Read(FILE* file)
{
	//Read the num of chars
	char sizeBuffer[sizeof(uint32_t)];
	fread(sizeBuffer, sizeof(uint32_t), 1, file);
	uint32_t* sizeOfString = reinterpret_cast<uint32_t*>(sizeBuffer);

	//Read a string
	char* stringBuffer = new char[sizeof(char)* (*sizeOfString)];
	fread(stringBuffer, sizeof(char), static_cast<size_t>(*sizeOfString), file);
	std::string tmp(stringBuffer);

	delete[] stringBuffer;

	return tmp;

}


void List::Serialize(FILE * file)
{
	assert(file);

	uint32_t sizeOfList = static_cast<uint32_t>(this->count);

	char* buf = reinterpret_cast<char*>(&sizeOfList);
	fwrite(buf, sizeof(uint32_t), 1, file);

	for (uint32_t i = 0; i < sizeOfList; i++)
	{
		Write(this->operator[](i)->data, file);
	}


}

void List::Deserialize(FILE * file)
{
	assert(file);
	this->ReleseNodes();

	//Read num of nodes
	char sizeBuffer[sizeof(uint32_t)];
	fread(sizeBuffer, sizeof(uint32_t), 1, file);
	uint32_t* sizeOfList = reinterpret_cast<uint32_t*>(sizeBuffer);

	//Read nodes
	for (uint32_t i = 0; i < *sizeOfList; i++)
	{
		std::string tmp = Read(file);
		this->Add(tmp);
	}

}

ListNode* List::operator[](int Nth)
{

	assert(Nth <= (count - 1));

	ListNode* iterator = head;
	while (Nth)
	{
		iterator = iterator->next;
		Nth--;
	}
	return iterator;
}

void List::ReleseNodes()
{
	while (count)
	{
		auto tmp = tail->prev;
		delete(tail);
		tail = tmp;
		count--;
	}
	head = nullptr;
}

void List::Add(std::string& value)
{
	ListNode* newNode = new ListNode();
	newNode->data = value;
	newNode->next = nullptr;
	newNode->prev = tail;
	newNode->rand = NULL;

	if (head == nullptr && tail == nullptr) { head = newNode; }
	else tail->next = newNode;
	tail = newNode;
	count++;
}
