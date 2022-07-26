
#include "data-structures/graph.h"


int main() {

	int beginningNode = 0;


	graph SampleGraph;

	std::cout << "Enter a node to begin Depth First Search with : ";
	std::cin >> beginningNode;

	SampleGraph.DFT(beginningNode);

	// std::cout << "Enter a node to begin Breadth First Search with : ";
	// std::cin >> beginningNode;

	// SampleGraph.BFT(beginningNode);

	return 0;
}





