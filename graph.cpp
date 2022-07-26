#include "graph.h"



graph::graph() {
	
	std::cout << "Enter the number of vertices : ";
	std::cin >> VertexNum;

	edgeListLen = new int[VertexNum];

	Vertices = new int[VertexNum];

	Visited = new bool[VertexNum];

	EdgeList = new int*[VertexNum];

	std::cout << "Enter the Vertices :" << std::endl;
	for (int i = 0; i < VertexNum; i++) {
		std::cin >> Vertices[i];
		Visited[i] = false;
	}


	for (int i = 0; i < VertexNum; i++) {

		std::cout << "Enter the number of adjacent vertices of vertex " << Vertices[i] << " : ";
		std::cin >> edgeListLen[i];

		EdgeList[i] = new int[edgeListLen[i]];

		std::cout << "Enter the adjacent vertices of vertex " << Vertices[i] << " : \n";
		for (int j = 0; j < edgeListLen[i]; j++) {
			std::cin >> EdgeList[i][j];
		}
	}

	for (int subarr = 0, arr = 0; arr < VertexNum; arr++) {

		std::cout << "\n" << Vertices[arr] << " => ";

		for (subarr = 0; subarr < edgeListLen[arr]; subarr++) {
			std::cout << EdgeList[arr][subarr] << " ";
		}

		std::cout << "\n";
	}
}

/*

bool graph::AddEdge(int* vertex1, int* vertex2) {

}

*/


int graph::searchPos(int VrtValue) {
	
	bool vertexSearchFlag = false;

	try {
		for (int arrVal = 0; arrVal < VertexNum; arrVal++) {
			if (Vertices[arrVal] == VrtValue) {
				return arrVal;
			}
		}

		if (vertexSearchFlag == false) {
			throw 101;
		}
	}
	catch (int errValue) {

		std::cerr << errValue << "Value Not Found." << std::endl;
		
		return -3333;
	}
}


void graph::DFT(int startFromNode) {

	int NodePos = searchPos(startFromNode);

	std::cout << " " << Vertices[NodePos];
	Visited[NodePos] = true;

	if (NodePos != -3333) {

		for (int range = 0; range < edgeListLen[NodePos]; range++) {

			// To find if the node has not been visited yet.
			// Range travels over the the length of array that EdgeList[NudePos] points to.
			// searchPos queries the position of the vertex in the vertices list
			// This queried value is then passed in the Visited array to check if it is already visited or not.
			// if not then it calls depth first search on it 
			// otherwise it continues to the next iteration

			if (Visited[searchPos(EdgeList[NodePos][range])] == false) {
				
				DFT(EdgeList[NodePos][range]);
			}
			else {
				continue;
			}
		}
	}
}

