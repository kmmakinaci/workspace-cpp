/*
 * DWGraph.h
 *
 *  Created on: Sep 11, 2021
 *      Author: mert
 */

#ifndef DWGRAPH_H_
#define DWGRAPH_H_

#include "DiGraph.h"

class DWGraph:public DiGraph  {
protected:
	///@brief Struct of adjancent list vertices members
	struct Vertex
	{
		int cost;
	};

	///@brief Struct of graph edge mebers
	struct Edge
	{
		int weigth;
	};
public:
	DWGraph();
	DWGraph(Edge edges[], int n, int nV);
	virtual ~DWGraph();

	DWGraph::Vertex* getAdjListNode(int val,int weight, DWGraph::Vertex* head);
	void addEdge(int x, int y, int weight);
	void printAdjList(DWGraph::Vertex* v);
};

#endif /* DWGRAPH_H_ */
