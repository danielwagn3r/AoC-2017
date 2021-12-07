#include <iostream>
#include <boost/container/string.hpp>
#include <boost/program_options.hpp>

#include "corruption_checksum.h"
#include "abstract_part.h"
#include "part_one.h"
#include "part_two.h"

namespace po = boost::program_options;

int main(int argc, char** argv)
{
	po::options_description od;
	od.add_options()
		("part", po::value<unsigned int>()->default_value(1), "Part of puzzle.")
		("input", po::value<boost::container::string>()->default_value(""), "Input file.")
		("help", "Display this information.");

	po::positional_options_description pod;
	pod.add("part", 1);
	pod.add("input", 1);

	po::options_description cmdline_options("Usage:");
	cmdline_options.add(od);

	po::variables_map vm;

	try
	{
		store(po::command_line_parser(argc, argv).options(od).positional(pod).run(), vm);
		notify(vm);
	}
	catch (po::error e)
	{
		std::cerr << e.what() << std::endl;
		if (vm.count("help"))
		{
			std::cout << od << std::endl;
			return EXIT_FAILURE;
		}
		return EXIT_FAILURE;
	}

	if (vm.count("help"))
	{
		std::cout << "CorruptionChecksum [options] part input" << std::endl;
		std::cout << od << std::endl;
		return EXIT_FAILURE;
	}

	abstract_part* part = nullptr;

	try
	{
		switch (vm["part"].as<unsigned int>())
		{
		case 1:
			part = new part_one(vm["input"].as<boost::container::string>());
			break;
		case 2:
			part = new part_two(vm["input"].as<boost::container::string>());
			break;
		default:
			std::cerr << "Part '" << vm["part"].as<unsigned int>() << "' is invalid" << std::endl;
			return EXIT_FAILURE;
		}

		part->run();
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
