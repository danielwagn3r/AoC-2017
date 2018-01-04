#ifndef PART_TWO_H
#define PART_TWO_H

#include "abstract_part.h"

class part_two :
	public abstract_part
{
private:
	int sum_of_divisible_pair(boost::container::vector<int> numbers);

public:
	part_two(const boost::container::string &input);
	~part_two();

	void run() override;
};

#endif