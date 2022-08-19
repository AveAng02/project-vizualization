

#include <iostream>

#include "display-variables.h"

#include "Queue.h"

#include "frontend.h"



int main() {

	int midx = 0 , midy = 0 , iteration = 0, counter = 0;

	int x = 0, y = 0;

	Queue sample;

	sample.push(34);
	sample.push(14);
	sample.push(10);

	// Defining the window
	initwindow( WINDOW_WIDTH, WINDOW_HEIGHT, "PROJECT VIZUALIZATION", true);

	midx = getmaxx() / 2 ;
	midy = getmaxy() / 2 ;

	rectangle(midx, midy, midx - 100, midy - 50);

	while (1) {

		if (ismouseclick(WM_LBUTTONDOWN)) {

			getmouseclick(WM_LBUTTONDOWN, x, y);

			std::cout << "LEFT : ";

			std::cout << "x=" << x;

			std::cout << " y=" << y << std::endl;

			drawRectangle(x, y);
		}
		else if (ismouseclick(WM_RBUTTONDOWN)) {

			getmouseclick(WM_RBUTTONDOWN, x, y);

			std::cout << "RIGHT : ";

			std::cout << "x=" << x;

			std::cout << " y=" << y << std::endl;

			drawCircle(100, x, y);
		}

		delay(1000);
	}


	while (!kbhit())
	{
		delay(200);
	}


	return 0;
}





