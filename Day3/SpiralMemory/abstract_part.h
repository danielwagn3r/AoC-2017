#ifndef ABSTRACT_PART_H
#define ABSTRACT_PART_H

#include <boost/container/string.hpp>
#include <boost/filesystem.hpp>

class abstract_part
{
protected:
	const unsigned int input;

public:
	abstract_part(unsigned int input);
	virtual ~abstract_part();

	virtual void run() = 0;
};

#endif
