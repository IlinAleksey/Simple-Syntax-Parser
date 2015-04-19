#include <iostream>
#include "Production.h"
#include "LrItem.h"
int main()
{
	Production prod;
	prod.set_lhs(Symbol(false, 1));
	prod.append_rhs(Symbol(true, 1));
	std::cout << prod << std::endl;
	LrItem lritem(prod);
	std::cout << lritem << std::endl;
	return 0;
}