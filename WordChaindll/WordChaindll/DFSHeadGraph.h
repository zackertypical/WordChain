#pragma once

#include "DFSGraph.h"
static const char * head_out_of_range_error = "Head must be in range";

class DFSHeadGraph :public DFSGraph
{
protected:
	//��¼ÿ���ڵ��Ƿ�ͷ��ָ��������ĸ
	vector<bool> m_head;

public:
	DFSHeadGraph(int n);
	virtual ~DFSHeadGraph();
	virtual void setHeadSingle(int index);
	virtual void findAnsChain() override;
};