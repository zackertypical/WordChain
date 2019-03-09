#include "stdafx.h"
#include "DFSGraph.h"

DFSGraph::DFSGraph(int n):BaseGraph(n)
{
	visited.assign(vertexNum + 1, 0);
	parent.assign(vertexNum + 1, 0);
	child.assign(vertexNum + 1, 0);
	dp.assign(vertexNum + 1, 0);

}

DFSGraph::~DFSGraph()
{
}

void DFSGraph::findAnsChain() 
{
	visited.assign(vertexNum + 1, 0);
	//所有节点深度优先遍历
	for (int i = 1; i <= vertexNum; i++)
	{
		//visited[i] = 1;
		int temp_len;
		if (m_hasCircle)
			temp_len = dfs(i);
		else
			temp_len = dpDfs(i);
		if (temp_len > chain_len)
		{
			chain_head = i;
			chain_len = temp_len;
		}
		//visited[i] = 0;
	}
	child.assign(vertexNum + 1, 0);
	if (m_hasCircle)
		dfs(chain_head);
	else
		dpDfs(chain_head);
	int j;
	for (j = chain_head; j != 0; j = child[j])
	{
		//循环的状况！！
		if (find(ans_chain.begin(), ans_chain.end(), j) != ans_chain.end())
		{
			cout << "loop" << endl;
		}
		ans_chain.push_back(j);
	}
}

int DFSGraph::dfs(int index)
{
	visited[index] = 1;
	//int &len = dp[index];
	//
	//if (len > 0)
		//return len;
	//len  = 0;
	int len = vertexWeight[index];
	for (int i = 0; i < adjacentMatrix[index].size(); i++)
	{
		int next_vertex = adjacentMatrix[index][i];
		int temp_len = 0;
		if (visited[next_vertex])
		{
			//m_hasCircle = true;
			//dp[next_edge.vec] = -1;
		}
		else 
		{
			temp_len = dfs(next_vertex) + vertexWeight[index];
			if (temp_len > len)
			{
				len = temp_len;
				parent[next_vertex] = index;
				child[index] = next_vertex;
			}
		}
		
	}
	visited[index] = 0;
	return len;
}


int DFSGraph::dpDfs(int index)
{
	int &len = dp[index];
	//
	if (len > 0)
		return len;
	//len  = 0;
	visited[index] = 1;
	
	len = vertexWeight[index];
	for (int i = 0; i < adjacentMatrix[index].size(); i++)
	{
		int next_vertex = adjacentMatrix[index][i];
		int temp_len = 0;
		if (visited[next_vertex])
		{
			m_hasCircle = true;
			//dp[next_edge.vec] = -1;
		}
		else
		{
			temp_len = dpDfs(next_vertex) + vertexWeight[index];
			if (temp_len > len)
			{
				len = temp_len;
				parent[next_vertex] = index;
				child[index] = next_vertex;
			}
		}

	}
	visited[index] = 0;
	return len;
}

//先判断是否有环 public
bool DFSGraph::hasCircle()
{
	//所有节点深度优先遍历
	for (int i = 1; i <= vertexNum; i++)
	{
		dpDfs(i);
		//默认模式不能有圈
		if (m_hasCircle)
			return true;
	}
	return false;
}

//不用判断环的情况下直接调用此方法 public
const vector<int>& DFSGraph::getAnsChain()
{
	visited.assign(vertexNum + 1, 0);
	parent.assign(vertexNum + 1, 0);
	child.assign(vertexNum + 1, 0);
	dp.assign(vertexNum + 1, 0);

	findAnsChain();

	return ans_chain;
}


