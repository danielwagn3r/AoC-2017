#include <iostream>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/container/vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "part_one.h"

part_one::part_one(const boost::container::string& input) : abstract_part(input)
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
		int sum = 0;

		while (std::getline(ifs, line))
		{
			boost::container::vector<std::string> tokens;
			boost::container::vector<int> numbers;

			split(tokens, line, boost::is_any_of("\t"));
			numbers.resize(tokens.size());

			std::transform(tokens.begin(), tokens.end(), numbers.begin(), boost::lexical_cast<int, std::string>);

			const std::pair<boost::container::vector<int>::iterator, boost::container::vector<int>::iterator> result = boost::
				minmax_element(numbers.begin(), numbers.end());

			sum += *(result.second) - *(result.first);
		}

		std::cout << "sum: " << sum << std::endl;
	}
	catch (const std::ios_base::failure& e)
	{
		std::cout << e.what() << std::endl;
	}
}
