#include <string>

// структуру ListNode модифицировать нельзя
struct ListNode {
	ListNode *      prev;
	ListNode *      next;
	ListNode *      rand; // указатель на произвольный элемент данного списка либо NULL
	std::string     data;
};

class List {
public:
	void Serialize(FILE * file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
	void Deserialize(FILE * file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))

	//helper functions
	ListNode* operator[](int Nth);
	void ReleseNodes();
	void Add(std::string& value);
	int Count() { return count; }

private:
	ListNode *      head;
	ListNode *      tail;
	int       count;
};
