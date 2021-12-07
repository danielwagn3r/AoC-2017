#include <boost/filesystem.hpp>

#include "abstract_part.h"

using namespace boost::filesystem;

abstract_part::abstract_part(const boost::container::string& input)
	: input_path(input.c_str())
{
	try
	{
		file_status s = status(input_path);
		//std::cout << std::boolalpha << is_regular_file(s) << std::endl;

		if (!is_regular_file(s))
		{
			throw std::invalid_argument("invalid file specified");
		}
	}
	catch (filesystem_error& e)
	{
		throw std::runtime_error("an error occured");
	}
}


abstract_part::~abstract_part()
{
}
