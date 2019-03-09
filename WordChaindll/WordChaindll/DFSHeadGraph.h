#pragma once

#include "DFSGraph.h"

class DFSHeadGraph :public DFSGraph
{
protected:
	//记录每个节点是否开头是指定的首字母
	vector<bool> m_head;

public:
	DFSHeadGraph(int n);
	virtual ~DFSHeadGraph();
	virtual void setHeadSingle(int index);
	virtual void findAnsChain();
};