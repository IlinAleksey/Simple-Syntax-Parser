#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
class Symbol
{
	
public:
	bool terminal;
	int index;

	Symbol() : terminal(true), index(0){}
	Symbol(bool terminal, int index) : terminal(terminal), index(index){}
	~Symbol();
	bool operator==(const Symbol& other)
	{
		return (terminal == other.terminal) && (index == other.index);
	}
};

namespace std {

	template <>
	struct hash<Symbol>
	{
		std::size_t operator()(const Symbol& k) const
		{
			using std::size_t;
			using std::hash;
			using std::string;

			return ((hash<int>()(k.terminal + 1)
				^ (hash<int>()(k.index) << 1)) >> 1);
		}
	};

}