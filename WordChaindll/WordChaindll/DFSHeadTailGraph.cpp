#include "stdafx.h"
#include "DFSHeadTailGraph.h"


DFSHeadTailGraph::DFSHeadTailGraph(int n):DFSHeadGraph(n)
{
	m_tail.assign(n + 1, false);
}


DFSHeadTailGraph::~DFSHeadTailGraph()
{
}


void DFSHeadTailGraph::setTailSingle(int index)
{
	if (index > vertexNum)
		throw exception(tail_out_of_range_error);
	m_tail[index] = true;
}

void DFSHeadTailGraph::findAnsChain()
{
	visited.assign(vertexNum + 1, 0);
	for (int i = 1; i <= vertexNum; i++)
	{
		child.assign(vertexNum + 1, 0);
		if (m_head[i])
		{
			dfs(i);
			vector<int> tempChain;
			for (int j = i; j != 0; j = child[j])
			{
				if (find(tempChain.begin(), tempChain.end(), j) != tempChain.end())
				{
					cout << "loop" << endl;
					j = 0;
					break;
				}
				tempChain.push_back(j);
			}
				
			for (int j = tempChain.size() - 1; j >= 0; j--)
			{
				if (m_tail[tempChain[j]])
				{
					break;
				}
				tempChain.pop_back();
			}
			saveChain.push_back(tempChain);
		}
	}

	for (unsigned int j = 0; j < saveChain.size(); j++)
	{
		int len = 0;
		for (unsigned int k = 0; k < saveChain[j].size(); k++)
		{
			len += vertexWeight[saveChain[j][k]];
		}
		if (len > chain_len)
		{
			chain_head = j;
			chain_len = len;
		}
	}
	//TODO:nochain
	ans_chain = saveChain[chain_head];

}

//todo::::
int DFSHeadTailGraph::dfs(int index)
{

	visited[index] = 1;
	bool contain = false;
	if (m_tail[index])
		contain = true;
	int len = vertexWeight[index];
	for (unsigned int i = 0; i < adjacentMatrix[index].size(); i++)
	{
		int next_vertex = adjacentMatrix[index][i];
		int temp_len = 0;
		//如果节点已经被访问过，并且有指向该节点的边
		//从1开始
		if (visited[next_vertex])
		{
			m_hasCircle = true;
		}
		else
		{
			if (m_tail[next_vertex])
				contain = true;
			
			temp_len = dfs(next_vertex);
			temp_len = temp_len + vertexWeight[index];
			if ((temp_len >= len))
			{
				len = temp_len;
				parent[next_vertex] = index;
				child[index] = next_vertex;
			}
			//if (m_tail[next_vertex])
			//{
				//if (temp_len > headtail_len)
				//{
					//headtail_len = temp_len;
					//temp_tail = next_vertex;
					//temp_head2 = temp_head;//更新temp_head2
				//}
			//}
		}
	}
	visited[index] = 0;
	//如果递归到最深的地方，且不是尾巴，则返回0
	//如果上一级没有包含任何尾巴，且上一级下来都是0
	if ((len <= vertexWeight[index]) && !contain)
		return 0;
	return len;
}
