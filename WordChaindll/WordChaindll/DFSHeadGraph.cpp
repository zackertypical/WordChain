#include "stdafx.h"
#include"DFSHeadGraph.h"

DFSHeadGraph::DFSHeadGraph(int n) :DFSGraph(n)
{
	m_head.assign(n + 1, false);
}	


DFSHeadGraph::~DFSHeadGraph() {
	
}

void DFSHeadGraph::findAnsChain()
{
	visited.assign(vertexNum + 1, 0);
	for (int i = 1; i <= vertexNum; i++)
	{
		if (m_head[i])
		{
			int temp_len;
			if (m_hasCircle)
				temp_len = dfs(i);
			else
				temp_len = dpDfs(i);
			//加上自己的长度
			//temp_len += vertexWeight[i];
			if (temp_len > chain_len)
			{
				chain_head = i;
				chain_len = temp_len;
			}
		}
	}
	//chainhead没有被改变过
	if (chain_head == 0)
		return;
	child.assign(vertexNum + 1, 0);
	dfs(chain_head);
	int j;
	//todo:没有链的情况
	for (j = chain_head; j != 0; j = child[j])
	{
		//cout << j << endl;
		ans_chain.push_back(j);
	}
}

void DFSHeadGraph::setHeadSingle(int index)
{
	m_head[index] = true;
}
