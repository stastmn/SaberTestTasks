// Напишите функцию, которая принимает на вход знаковое целое число и печатает
// его двоичное представление, не используя библиотечных классов или функций. 

#include "BinNumbers.h"
#include <climits>
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

	return 0;
}


