#pragma once

#include "stdafx.h"

using namespace std;

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

