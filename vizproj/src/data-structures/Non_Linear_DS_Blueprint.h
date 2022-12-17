#pragma once

#include "DS_Blueprint.h"

class non_linear_DS : public Data_structure
{

public:

	non_linear_DS() {}

	virtual bool take_data_input() override;

	virtual bool delete_data() override;

	virtual void display_structure() override;

	virtual void breadth_first_traversal() = 0;

	virtual void depth_first_traversal() = 0;
};
