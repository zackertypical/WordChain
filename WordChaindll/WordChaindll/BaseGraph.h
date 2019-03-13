#pragma once

#include "stdafx.h"

using namespace std;

static const char * edge_out_of_range_error = "Edge must be in range";
static const char * vertex_out_of_range_error = "Vertex must be in range";
class BaseGraph
{
protected:
	
	//vector<T> vertex;
	int vertexNum = 0;
	int edgeNum = 0;
	vector<int> vertexWeight;//点的权重
	//存储边，x是编号，adjancentMatrix[x]是边的数组
	vector<vector<int> > adjacentMatrix;


public:
	BaseGraph(int n);
	virtual ~BaseGraph();
	virtual void insertEdge(int i, int j);
	virtual void changeVecWeigh(int i, int weight);

	//get
	virtual int getVertexNum () const;
	virtual int getEdgeNum () const;
};

