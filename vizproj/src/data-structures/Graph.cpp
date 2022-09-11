#include "Graph.h"



Graph::Graph() {
	
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

		std::cout << "NUMBER of adjacent vertices of vertex " << Vertices[i] << " : ";
		std::cin >> edgeListLen[i];

		EdgeList[i] = new int[edgeListLen[i]];

		std::cout << "ADJACENT VERTICES of vertex " << Vertices[i] << " : \n";
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

	adjMatrix = new int*[VertexNum];

	for (int i = 0; i < VertexNum; i++)
	{
		adjMatrix[i] = new int[VertexNum];
	}

	for (int j = 0, i = 0; i < VertexNum; i++)
	{
		for (j = i + 1; j < VertexNum; j++)
		{
			std::cout << "WEIGHT of edge between Vertex " << Vertices[i] << " and Vertex " << Vertices[j] << " : " << std::endl;
			std::cin >> adjMatrix[i][j];
		}
	}

	for (int j = 0, i = 0; i < VertexNum; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j)
			{
				adjMatrix[i][j] = 0;
			}
			else
			{
				adjMatrix[i][j] = adjMatrix[j][i];
			}
		}

		for (j = 0; j < VertexNum; j++)
		{
			std::cout << " | " << adjMatrix[i][j];
		}

		std::cout << "|\n" << std::endl;
	}

}

/*

bool Graph::AddEdge(int* vertex1, int* vertex2) {

}

*/


int Graph::searchPos(int VrtValue) {
	
	bool vertexSearchFlag = false;
		
	for (int arrVal = 0; arrVal < VertexNum; arrVal++) {
			
		if (Vertices[arrVal] == VrtValue) {
				return arrVal;
		}
		
	}

	return -3333;
}


void Graph::DFT(int startFromNode) {

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


void Graph::BFT(int startFromNode) {
	
	int nodepos = searchPos(startFromNode); // stores the position of the starting node 
	int printvert = 0;

	edgeQ.push(Vertices[nodepos]); // pushes the vertices at the nodepos into the queue

	Visited[nodepos] = true; // marks the nodepos as visited

	while (!edgeQ.isEmpty()) {

		printvert = edgeQ.gettop(); // saves the value of the top of the queue

		std::cout << printvert << " " ; // prints the element at the top

		edgeQ.pop(); // removes the top element

		for (int pos = searchPos(printvert), counter = 0; counter < edgeListLen[pos]; counter++) {

			if (Visited[searchPos(EdgeList[pos][counter])] == false) {

				edgeQ.push(EdgeList[pos][counter]); // if the node is not visited already it adds it at the back of the queue
				Visited[searchPos(EdgeList[pos][counter])] = true;

			}

		}

	}

	std::cout << "\n";

}





/*
BinarySearchTree Graph::MST(int VrtVal)
{

}
*/
