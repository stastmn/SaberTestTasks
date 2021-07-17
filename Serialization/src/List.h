#include <string>

// ��������� ListNode �������������� ������
struct ListNode {
	ListNode *      prev;
	ListNode *      next;
	ListNode *      rand; // ��������� �� ������������ ������� ������� ������ ���� NULL
	std::string     data;
};

class List {
public:
	void Serialize(FILE * file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
	void Deserialize(FILE * file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))

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
