#include "Graph.h"



Graph::Graph() {
	
	// Takes in the number of vertices
	std::cout << "Enter the number of vertices : ";
	std::cin >> VertexNum;


	edgeListLen = new int[VertexNum];

	Vertices = new int[VertexNum];

	Visited = new bool[VertexNum];

	EdgeList = new int*[VertexNum];

	// Takies input the vertices themselves and marks them as unvisited
	std::cout << "Enter the Vertices :" << std::endl;
	for (int i = 0; i < VertexNum; i++) 
	{
		std::cin >> Vertices[i];
		Visited[i] = false;
	}


	// Creates the adjacency list
	for (int i = 0; i < VertexNum; i++) 
	{

		std::cout << "NUMBER of adjacent vertices of vertex " << Vertices[i] << " : ";
		std::cin >> edgeListLen[i];

		EdgeList[i] = new int[edgeListLen[i]];

		std::cout << "ADJACENT VERTICES of vertex " << Vertices[i] << " : \n";
		for (int j = 0; j < edgeListLen[i]; j++) {
			std::cin >> EdgeList[i][j];
		}
	}


	// Prints the Adjacency list
	for (int subarr = 0, arr = 0; arr < VertexNum; arr++) 
	{

		std::cout << "\n" << Vertices[arr] << " => ";

		for (subarr = 0; subarr < edgeListLen[arr]; subarr++) {
			std::cout << EdgeList[arr][subarr] << " ";
		}

		std::cout << "\n";
	}

	// Defines the adjacency matrix in memory
	adjMatrix = new int*[VertexNum];

	for (int j = 0, i = 0; i < VertexNum; i++)
	{
		adjMatrix[i] = new int[VertexNum];

		for (j = 0; j < VertexNum; j++)
		{
			adjMatrix[i][j] = std::numeric_limits<int>::max();
		}
	}


	// takes the weights input for the adjacency matrix
	for (int k = 0, j = 0, i = 0; i < VertexNum; i++)
	{
		// This block searches for the first value of k for which the edge is already not assigned weight
		k = 0;
		
		while (searchPos(EdgeList[i][k]) < i + 1)
		{
			k++;

			if (k == edgeListLen[i])
			{
				break;
			}
		}

		for (j = i + 1; j < VertexNum && k < edgeListLen[i]; j++)
		{
			if (Vertices[j] == EdgeList[i][k])
			{
				// If block that takes input the weights of the vertices
				std::cout <<"WEIGHT of edge between Vertex " << Vertices[i] << " and Vertex " << Vertices[j] << " : " << std::endl;
				std::cin >> adjMatrix[i][j];
				k++;
			}

			adjMatrix[j][i] = adjMatrix[i][j];
			std::cout << "Experimental new line added." << std::endl;
		}
	}


	// Prints the matrix
	for (int j = 0, i = 0; i < VertexNum; i++)
	{
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

	return std::numeric_limits<int>::max();
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


std::vector<int> Graph::dijkstraAlgo(int VertexBegin, int VertexDest) // Function returns a vector containing the path nodes
{                                                                     // it accepts the two vertices; the beginning and the end
	std::cout << "\n" << " Marker : Function Beginning; " << "\n" << std::endl;
	std::vector<int> ShortestPath;

	ShortestPath.push_back(VertexBegin);

	Visited[searchPos(VertexBegin)] = true;

	for (int min = 0, j = 0, i = searchPos(VertexBegin); i < VertexNum; i++)
	{
		std::cout << "\n" << " Marker : Main Loop; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;

		min = EdgeList[i][j]; // sets the first edge on the list as the reference
		                      // the rest will be checked against the first edge

		std::cout << "\n" << " Marker : Minimum updated; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;
		
		for (j = 0; j < edgeListLen[i]; j++)
		{
			std::cout << "\n" << " Marker : Sub loop; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;

			if (EdgeList[i][j] == VertexDest)
			{
				std::cout << "\n" << " Marker : Exit condition fulfiled; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;

				ShortestPath.push_back(EdgeList[i][j]);

				goto algoEnd;
			}
			
			if (Visited[searchPos(EdgeList[i][j])] != true) // if block to make sure that the vertex is not previously visited
			{
				std::cout << "\n" << " Marker : Un-explored Vertex found; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;
				
				// this if block compares 
				//  a new adj value                                            with                    previous minimum
				if (adjMatrix[searchPos(VertexBegin)][searchPos(EdgeList[i][j])] < adjMatrix[searchPos(VertexBegin)][searchPos(min)])
				{
					// the minimum is updated and the Vertex is marked as visited
					min = Vertices[searchPos(EdgeList[i][j])];

					Visited[searchPos(EdgeList[i][j])] = true;

					std::cout << "\n" << " Marker : New Minimum found; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;

					std::cout << "\n" << " searchPos(VertexBegin) : " << searchPos(VertexBegin) << " ; searchPos(EdgeList[i][j]) : " << searchPos(EdgeList[i][j]) << " ; searchPos(min) : " << searchPos(min) << "\n" << std::endl;

					std::cout << " adjMatrix[searchPos(VertexBegin)][searchPos(EdgeList[i][j])] : " << adjMatrix[searchPos(VertexBegin)][searchPos(EdgeList[i][j])] << " ; adjMatrix[searchPos(VertexBegin)][searchPos(min)] : " << adjMatrix[searchPos(VertexBegin)][searchPos(min)] << std::endl;
				}
			}
		}

		std::cout << "\n" << " Marker : Updating Values with Minimum; " << "min : " << min << " ; i : " << i << " ; j : " << j << "\n" << std::endl;

		// The minimum is added to the list of vertex
		ShortestPath.push_back(min);

		// VertexBegin is updated to new minimum
		VertexBegin = min;

		// i is updated to the position of new VertexBegin
		i = searchPos(VertexBegin);
	}

	algoEnd:

	std::cout << "\n" << " Marker : Exited; " << "\n" << std::endl;

	return ShortestPath;
}


/*
BinarySearchTree Graph::MST(int VrtVal)
{

}
*/
