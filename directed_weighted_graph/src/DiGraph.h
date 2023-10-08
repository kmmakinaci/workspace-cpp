/*
 * DiGraph.h
 *
 *  Created on: Sep 10, 2021
 *      Author: mert
 */

#ifndef DIGRAPH_H_
#define DIGRAPH_H_

#include <list>

/***
 * @brief Class for base directed graph
 */


class DiGraph {

protected:
	///@brief Struct for Adjancent list vertices
	struct Vertex
	{
		int val;
		Vertex* next;
	};

	/// @brief Struct for edge
	struct Edge {
		int src;
		int dest;
	};

	/// @brief Number of vertices in graph
	int nV;

	/// @brief Struct for an adjacency list
//	struct AdjList{
//		Vertex *head;
//	};
	/// @brief Array of adjacent lists
//	AdjList *adjListArr;
	Vertex **adjList;

public:
	// Ctors, Dtor
	DiGraph();
	DiGraph(int N);
	DiGraph(Edge edges[], int n, int nV);
	virtual ~DiGraph();

	// Member functions declaration
	Vertex* getAdjListNode(int val, Vertex* head);
	void addEdge(int x, int y);
	void printAdjList(Vertex* v);
};

#endif /* DIGRAPH_H_ */
