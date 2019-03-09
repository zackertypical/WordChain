#include "stdafx.h"
#include "BaseGraph.h"


BaseGraph::BaseGraph(int n)
{
	vertexNum = n;
	adjacentMatrix.resize(n + 1);
	vertexWeight.assign(n + 1, 0);
}

 BaseGraph::~BaseGraph()
{
	
}

 void BaseGraph::changeVecWeigh(int i, int weight)
 {
	 vertexWeight[i] = weight;
 }

void BaseGraph::insertEdge(int i, int j) 
{
	adjacentMatrix[i].push_back(j);
}

//get
int BaseGraph::getVertexNum() const
{
	return vertexNum;
}
int BaseGraph::getEdgeNum() const
{
	return edgeNum;
}