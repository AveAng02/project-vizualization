
#include "graph.h"


int main() {

	int beginningNode = 0;


	graph SampleGraph;

	std::cout << "Enter a node to begin with : ";
	std::cin >> beginningNode;

	SampleGraph.DFT(beginningNode);

	return 0;
}





