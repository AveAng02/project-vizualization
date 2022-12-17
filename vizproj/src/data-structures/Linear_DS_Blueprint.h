#pragma once

#include "DS_Blueprint.h"

class linear_DS : public Data_structure
{

public:

	linear_DS() {}


	virtual bool take_data_input() override; 

	virtual bool delete_data() override; 

	virtual void display_structure() override;

	virtual void searching() = 0;

	virtual void sorting() = 0;
};








