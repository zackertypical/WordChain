#pragma once

#include "stdafx.h"

using namespace std;

class BaseGraph
{
protected:
	
	//vector<T> vertex;
	int vertexNum = 0;
	int edgeNum = 0;
	vector<int> vertexWeight;//���Ȩ��
	//�洢�ߣ�x�Ǳ�ţ�adjancentMatrix[x]�Ǳߵ�����
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

