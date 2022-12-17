#pragma once



// namespace vizproj


class Data_structure
{
public:

	Data_structure() {}


	// used to input data in the data structure
	virtual bool take_data_input() = 0; // pass the class named payload in the take_data function to send the data in the ds

	virtual bool delete_data() = 0; // deleting data from the data structure

	// displays the data structure on the screen
	virtual void display_structure() = 0;

private:


};








