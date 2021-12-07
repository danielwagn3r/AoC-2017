#include <boost/filesystem.hpp>

#include "abstract_part.h"

using namespace boost::filesystem;

abstract_part::abstract_part(unsigned int input)
	: input(input)
{
	if (input < 1)
		throw std::invalid_argument("input can not be zero.");
}


abstract_part::~abstract_part()
{
}
