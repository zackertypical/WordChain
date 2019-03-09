#pragma once
#include "DFSHeadGraph.h"
class DFSHeadTailGraph :
	public DFSHeadGraph
{
private :
	vector<vector<int> > saveChain;
	vector<bool> m_tail;
	int headtail_len = 0; 
	//int chain_len = 0;
	//int chain_head = 0;
	int chain_tail = 0;
	int temp_tail = 0;
	int temp_head = 0;
	
	virtual int dfs(int index);
public:
	DFSHeadTailGraph(int n);
	~DFSHeadTailGraph();
	virtual void setTailSingle(int index);
	virtual void findAnsChain();
};

