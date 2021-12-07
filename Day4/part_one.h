#ifndef PART_ONE_H
#define PART_ONE_H

#include "abstract_part.h"

class part_one :
	public abstract_part
{
public:
	part_one(const boost::container::string &input);
	~part_one();

	void run() override;
};

#endif