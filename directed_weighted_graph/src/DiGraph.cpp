/*
 * DiGraph.cpp
 *
 *  Created on: Sep 11, 2021
 *      Author: mert
 */
#include <iostream>
using namespace std;

#include "DiGraph.h"

DiGraph::DiGraph() {
	// TODO Auto-generated constructor stub
	this->nV = 0;
	adjList = nullptr;
}

DiGraph::DiGraph(int nV){
	this->nV= nV;

	// initialize head pointer for all vertices
	//l = new list<int>[V];
	for (int i = 0; i < nV; i++) {
		adjList[i] = nullptr;
	}
}

/***
 * @note Unused variable dest gives compiler warning
 */
DiGraph::DiGraph(Edge edges[], int val, int nV)
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

DiGraph::~DiGraph() {
	// TODO Auto-generated destructor stub
    for (int i = 0; i < this->nV; i++) {
        delete[] adjList[i];
    }

    delete[] adjList;
}

// Function to allocate a new node for the adjacency list
DiGraph::Vertex* DiGraph::getAdjListNode(int val, DiGraph::Vertex* head)
{
	Vertex* newV = new Vertex;
	newV->val = val;

	// point new node to the current head
	newV->next = head;

	return newV;
}

void DiGraph::addEdge(int x, int y){
	//l[x].push_back(y);
	//l[y].push_back(x);
}

void DiGraph::printAdjList(DiGraph::Vertex *v)
{

	//Iteratively prints all the vertices
	// print all adjacent vertices of given vertex
	int i=0;
	    while (v != nullptr) {
	        cout << "(" << i++ << "," << v->val << ") ";
	        v = v->next;
	    }
	    cout << endl;
}

