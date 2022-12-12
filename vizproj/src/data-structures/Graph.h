#pragma once

// Predifines Library

#include <iostream>
#include <vector>
#include <limits>

// Custom Library

#include "Queue.h"



class Graph {

private:

	int VertexNum; // stores the number of vertices

	int* Vertices = nullptr; // stores the vertices 

	// ADJACENCY LIST
	int* edgeListLen = nullptr; // stores the number of edges of each vertex

	bool* Visited = nullptr; // Stores boolean flags that can be used to check if the node is visited or not

	int** EdgeList = nullptr; // Stores the edges 
	
	Queue edgeQ;

	// ADJACENCY MATRIX
	int** adjMatrix; 



public:
	Graph();

	// bool AddEdge(int* vertex1, int* vertex2);

	// Returns the position, of the vertex passed, in the vertices array
	int searchPos(int VrtValue);

	// Depth first traversal
	void DFT(int startFromNode);

	// Breadth First Traversal
	void BFT(int startFromNode);

	// Finding the shortest path between two points using the Dijkstra Algorithm
	std::vector<int> dijkstraAlgo(int VertexBegin, int VertexDest);


	// BinarySearchTree MST(int VrtValue);

	/*
		
		Shortest Path Algoritms:




	*/

};









