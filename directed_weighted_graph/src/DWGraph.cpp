/*
 * DWGraph.cpp
 *
 *  Created on: Sep 11, 2021
 *      Author: mert
 */
#include <iostream>
using namespace std;

#include "DWGraph.h"

DWGraph::DWGraph() {
	// TODO Auto-generated constructor stub

}

/***
 * @note Unused variable dest gives compiler warning
 */
DWGraph::DWGraph(Edge edges[], int val, int nV)
{
	// allocate memory
	adjList = new Vertex*[nV]();
	this->nV= nV;

	// initialize head pointer for all vertices
	for (int i = 0; i < nV; i++) {
		adjList[i] = nullptr;
	}

	// add edges to the directed graph
	for (int i = 0; i < nV; i++)
	{
		int src = edges[i].src;
		int dest = edges[i].dest;
		int cost = edges[i].cost;

		// insert at the beginning
		Vertex* newV = getAdjListNode(val, adjList[src]);

		// point head pointer to the new node
		adjList[src] = newV;

		// uncomment the following code for undirected graph

		/*
            newNode = getAdjListNode(src, head[dest]);

            // change head pointer to point to the new node
            head[dest] = newNode;
		 */
	}
}

DWGraph::~DWGraph() {
	// TODO Auto-generated destructor stub
}

