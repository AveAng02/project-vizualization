#pragma once

#include "DS_Blueprint.h"


class abstract_DS : public Data_structure
{

public:

	abstract_DS() {}

	virtual bool take_data_input() override;

	virtual bool delete_data() override;

	virtual void display_structure() override;

};

