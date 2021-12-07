#include <iostream>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/container/set.hpp>
#include <boost/container/vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "part_one.h"

part_one::part_one(const boost::container::string &input) : abstract_part(input)
{
}

part_one::~part_one()
{
}

void part_one::run()
{
	boost::filesystem::ifstream ifs;

	ifs.open(input_path, boost::filesystem::ifstream::in);

	try
	{
		std::string line;

		while (std::getline(ifs, line))
		{
			boost::container::vector<std::string> tokens;
			boost::container::vector<int> numbers;

			split(tokens, line, boost::is_any_of(" \t"));
			numbers.resize(tokens.size());

			boost::container::set<int> number_set;

			for(auto it=numbers.begin(); it != numbers.end(); ++it)
			{
				auto x = number_set.find(*it);
				// std::cout << *it << ((number_set.find(*it))?"*":"!") << std::endl;
				// number_set.insert(*it);
			}
		}
	}
	catch (const std::ios_base::failure &e)
	{
		std::cout << e.what() << std::endl;
	}
}
