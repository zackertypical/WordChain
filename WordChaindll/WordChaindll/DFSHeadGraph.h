#pragma once

#include "DFSGraph.h"

class DFSHeadGraph :public DFSGraph
{
protected:
	//��¼ÿ���ڵ��Ƿ�ͷ��ָ��������ĸ
	vector<bool> m_head;

public:
	DFSHeadGraph(int n);
	virtual ~DFSHeadGraph();
	virtual void setHeadSingle(int index);
	virtual void findAnsChain();
};