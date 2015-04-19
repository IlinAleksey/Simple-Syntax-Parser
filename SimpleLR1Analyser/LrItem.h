#pragma once
#include "Production.h"
#include "Symbol.h"
class LrItem :
	public Production
{
	Symbol lookahead;
	int position;
public:
	LrItem() : Production(), lookahead(Symbol()), position(0){}
	LrItem(Production production, Symbol lookahead = Symbol(), int position = 0);
	LrItem(Symbol lhs, Sequence rhs, Symbol lookahead = Symbol(), int position = 0);
	~LrItem();

	Symbol get_symbol_at_position() const {
		if (position >= rhs.size())
		{
			return Symbol();
		}
		else
		{
			return rhs[position];
		}
	}
	Symbol get_lookahead() const { return lookahead; }
	Sequence get_suffix() const {
		if (position+1 >= rhs.size)
		{
			return Sequence();
		}
		else
		{
			Sequence suffix(rhs.begin() + position + 1, rhs.end());
			return suffix;
		}
	}
};

