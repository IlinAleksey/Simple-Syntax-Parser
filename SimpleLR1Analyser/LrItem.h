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
		if (position+1 >= rhs.size())
		{
			return Sequence();
		}
		else
		{
			Sequence suffix(rhs.begin() + position + 1, rhs.end());
			return suffix;
		}
	}
	friend std::ostream& operator<< (std::ostream& out, LrItem lritem)
	{
		out << "[" << lritem.get_lhs() << " ::= ";
		for (int i = 0; i < lritem.rhs.size(); i++)
		{
			if (lritem.position == i)
			{
				out << '.';
			}
			out << lritem.rhs[i];
		}
		if (lritem.position == lritem.rhs.size())
		{
			out << '.';
		}
		out << "; " << lritem.lookahead << "]";
		return out;
	}
};

