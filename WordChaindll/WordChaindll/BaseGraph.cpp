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
	 if (i > vertexNum)
		 throw exception(vertex_out_of_range_error);
	 vertexWeight[i] = weight;
 }

void BaseGraph::insertEdge(int i, int j) 
{
	if ((i > vertexNum)||(j > vertexNum))
		throw exception(edge_out_of_range_error);
	adjacentMatrix[i].push_back(j);
	edgeNum++;
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