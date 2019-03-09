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
			//temp_head = i;
			//headtail_len = 0;
			dfs(i);
			//headtail_len �ı�
			//�����Լ��ĳ���
			//if (headtail_len > chain_len)
			//{
				//chain_len = headtail_len;
				//chain_head = temp_head;
				//chain_tail = temp_tail;
			//}
			vector<int> tempChain;
			for (int j = i; j != 0; j = child[j])
				tempChain.push_back(j);
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

	//sort(saveChain.begin(), saveChain.end(), [](const vector<int>& a, const vector<int>& b)->bool {return a.size() > b.size(); });
	for (int j = 0; j < saveChain.size(); j++)
	{
		int len = 0;
		for (int k = 0; k < saveChain[j].size(); k++)
		{
			len += vertexWeight[saveChain[j][k]];
		}
		if (len > chain_len)
		{
			chain_head = j;
			chain_len = len;
		}
	}
	//chain_head = saveChain[0][0];
	//if (chain_head == 0)
		//return;
	//child.assign(vertexNum + 1, 0);
	//dfs(chain_head);
	//û���ҵ�
	//if (chain_tail == 0)
		//return;
	//int j;
	//todo:û���������
	//if (saveChain[chain_head].size()<2)
		//return;
	ans_chain = saveChain[chain_head];
	//for (int j = chain_head; j != chain_tail; j = child[j])
	{
		//cout << j << endl;
		//ans_chain.push_back(j);
	}
	//ans_chain.push_back(j);

}

//todo::::
int DFSHeadTailGraph::dfs(int index)
{

	visited[index] = 1;
	bool contain = false;
	if (m_tail[index])
		contain = true;
	int len = vertexWeight[index];
	for (int i = 0; i < adjacentMatrix[index].size(); i++)
	{
		int next_vertex = adjacentMatrix[index][i];
		int temp_len = 0;
		//����ڵ��Ѿ������ʹ���������ָ��ýڵ�ı�
		//��1��ʼ
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
			if ((temp_len > len))
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
					//temp_head2 = temp_head;//����temp_head2
				//}
			//}
		}
	}
	visited[index] = 0;
	//����ݹ鵽����ĵط����Ҳ���β�ͣ��򷵻�0
	//�����һ��û�а����κ�β�ͣ�����һ����������0
	if ((len <= vertexWeight[index]) && !contain)
		return 0;
	return len;
}
