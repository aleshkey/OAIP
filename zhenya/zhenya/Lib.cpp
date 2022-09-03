#include "Lib.h"
#include <iostream>
template<typename T>
void Lib<T>::Show()
{
	std::cout << count;
}

template<typename T>
void Lib<T>::SetCount(T x)
{
	count = x;
}
