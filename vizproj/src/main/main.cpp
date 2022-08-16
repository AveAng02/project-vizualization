

#include <iostream>

#include "display-variables.h"

#include "Queue.h"



int main() {

	Queue sample;

	// making window
	initwindow( WINDOW_HEIGHT, WINDOW_WIDTH, "Project Vizualization", true);

	
	sample.push(5);
	sample.push(12);
	sample.push(9);

	sample.drawQueue();


	// delay
	while (!kbhit())
	{
		delay(200);
	}

	return 0;
}





