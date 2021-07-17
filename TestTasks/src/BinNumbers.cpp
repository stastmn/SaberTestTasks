#pragma once
#include "BinNumbers.h"
#include <string>
#include <iostream>
#include <assert.h>


void printToBinNumerals(int decNum)
{
	//function works only when sizeof(int)=4 because we use fixed mask 0x80000000
	assert(sizeof(int) == 4);
#ifdef _DEBUG
	std::cout << decNum << " = ";

#endif
		
	std::string binRepr(sizeof(int) * 8, '*');

	for (int i = 0; i < sizeof(int) * 8; i++) 
	{
		if (decNum & 0x80000000)
		{
			binRepr[i] = '1';
		}
		else
		{
			binRepr[i] = '0';
		}
		decNum <<= 1;
	}
	
	std::cout << binRepr << std::endl;

}
