// �������� �������, ������� ��������� �� ���� �������� ����� ����� � ��������
// ��� �������� �������������, �� ��������� ������������ ������� ��� �������. 

#include "BinNumbers.h"
#include <climits>
#include <cstdlib>
int main()
{
	printToBinNumerals(0);
	printToBinNumerals(1);
	printToBinNumerals(8);
	printToBinNumerals(48567);
	printToBinNumerals(-25630);
	printToBinNumerals(-1);
	printToBinNumerals(INT_MAX);
	printToBinNumerals(INT_MIN);

	system("pause");
	return 0;
}


