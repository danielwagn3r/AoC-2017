#ifndef ABSTRACT_PART_H
#define ABSTRACT_PART_H

#include <boost/container/string.hpp>
#include <boost/filesystem.hpp>

class abstract_part
{
protected:
	boost::filesystem::path input_path;

public:
	abstract_part(const boost::container::string& input);
	virtual ~abstract_part();

	virtual void run() = 0;
};

#endif
