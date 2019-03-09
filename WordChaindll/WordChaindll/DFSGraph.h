#pragma once
#include "BaseGraph.h"


class DFSGraph : public BaseGraph
{
protected:
	vector<int> visited;
	vector<int> parent;
	vector<int> child;
	vector<int> dp;
	bool m_hasCircle = false;
	int chain_len = 0;
	int chain_head = 0;
	
	vector<int> ans_chain;

	virtual void findAnsChain();
	virtual int dfs(int index);
	virtual int dpDfs(int index);
	//void circleDetect(int index);

public:
	DFSGraph(int n);
	virtual ~DFSGraph();
	virtual const vector<int>& getAnsChain();
	virtual bool hasCircle();

};