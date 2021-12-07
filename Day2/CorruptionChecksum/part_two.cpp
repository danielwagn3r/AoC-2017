#include <iostream>
#include <boost/algorithm/minmax_element.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/container/vector.hpp>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "part_two.h"

part_two::part_two(const boost::container::string& input) : abstract_part(input)
{
}


part_two::~part_two()
{
}

int part_two::sum_of_divisible_pair(boost::container::vector<int> numbers)
{
	for (size_t a = 0; a < numbers.size(); ++a)
	{
		for (size_t b = 0; b < numbers.size(); ++b)
		{
			if (a == b)
				continue;

			if (numbers[a] % numbers[b] == 0)
				return numbers[a] / numbers[b];
		}
	}

	return 0;
}

void part_two::run()
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

			sum += sum_of_divisible_pair(numbers);
		}

		std::cout << "sum: " << sum << std::endl;
	}
	catch (const std::ios_base::failure& e)
	{
		std::cout << e.what() << std::endl;
	}
}
