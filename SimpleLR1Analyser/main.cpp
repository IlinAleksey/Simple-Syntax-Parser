#include <iostream>
#include "Production.h"
#include "LrItem.h"
#include "Oracle.h"
#include "ProductionLexer.h"
#include "OracleBuilder.h"
#include <string>
#include <set>

int main()
{
	/*OracleBuilder oracle_builder;
	oracle_builder.parse_productions("data.txt");
	std::cout << oracle_builder.production_list_to_string() << std::endl;
	oracle_builder.build_first_sets();
	std::cout << oracle_builder.first_sets_to_string() << std::endl;


	Production goal_production = oracle_builder.get_production_list()[0];
	LrItem goal_item = LrItem(goal_production);
	std::set<LrItem> initial_set = { goal_item };
	std::set<LrItem> initial_state = oracle_builder.closure(initial_set);

	for each (LrItem lritem in initial_state)
	{
		std::cout << lritem << ", ";
	}*/

	OracleBuilder oracle_builder2;
	oracle_builder2.build_oracle("data.txt");
	std::cout << oracle_builder2 << std::endl;

	/*OracleBuilder oracle_builder;
	oracle_builder.build_oracle("data.txt");
	std::cout << oracle_builder;*/
	return 0;
}