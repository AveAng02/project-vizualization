#include <iostream>
#include <vector>



class graph {

public:

	int VertexNum;

	int* edgeListLen = NULL;

	int* Vertices = NULL;

	bool* Visited = NULL;

	int** EdgeList = NULL;

	graph();

	// bool AddEdge(int* vertex1, int* vertex2);

	int searchPos(int VrtValue);

	void DFT(int startFromNode);

};









