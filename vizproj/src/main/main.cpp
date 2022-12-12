


#include "Graph.cpp"



int main() {

	// UI test block
	/*int midx = 0, midy = 0, iteration = 0, counter = 0;

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
	}*/

	Graph gph1;

	std::vector<int> path;

	int vrtstart = 0, vrtend = 0;

	std::cout << "Enter the starting Vertex : ";
	std::cin >> vrtstart;

	std::cout << "Enter the ending Vertex : ";
	std::cin >> vrtend;

	path = gph1.dijkstraAlgo(vrtstart, vrtend);

	for (int i = 0; i < path.size(); i++)
	{
		std::cout << path.at(i) << " -> ";
	}

	std::cout << std::endl;

	return 0;
}





