#pragma once

#include <iostream>
#include <vector>
#include "Queue.h"



class Graph {

public:

	int VertexNum;

	int* edgeListLen = nullptr;

	int* Vertices = nullptr;

	bool* Visited = nullptr;

	int** EdgeList = nullptr;

	Queue edgeQ;

	Graph();

	// bool AddEdge(int* vertex1, int* vertex2);

	int searchPos(int VrtValue);

	void DFT(int startFromNode);

	void BFT(int startFromNode);

};









