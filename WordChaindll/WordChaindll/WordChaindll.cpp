// WordChaindll.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "WordChaindll.h"



int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	Core core;

	core.insertChain(words, len);
	//print
	core.print_wordchain();
	//检测是否有环
	if (!enable_loop)
	{
		DFSGraph g(core.wordset_size);
		core.insert_noweighedEdge(g);
		if (g.hasCircle())
			//throw new.....
		{
			cout << "has circle" << endl;
			return 0;

		}

	}

	if (head && tail)
	{
		DFSHeadTailGraph graph(core.wordset_size);
		core.insert_noweighedEdge(graph);
		core.setHead(graph, head);
		core.setHeadTail(graph, tail);
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//输出
		core.getresult(result, ans);
		return ans.size();

	}
	else if (head)
	{
		DFSHeadGraph graph(core.wordset_size);
		core.insert_noweighedEdge(graph);
		core.setHead(graph, head);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//输出
		core.getresult(result, ans);
		return ans.size();
	}
	else if (tail)
	{
		DFSHeadGraph graph(core.wordset_size);
		//反向建图
		core.insert_noweighedReverseEdge(graph);
		core.setTail(graph, tail);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//反转
		reverse(ans.begin(), ans.end());
		core.getresult(result, ans);
		return ans.size();
	}
	else
	{
		DFSGraph graph(core.wordset_size);
		core.insert_noweighedEdge(graph);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		core.getresult(result, ans);
		return ans.size();
	}
	return 0;
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	Core core;
	core.insertChain(words, len);
	////打印
	core.print_wordchain();
	//检测是否有环
	if (!enable_loop)
	{
		DFSGraph g(core.wordset_size);
		core.insert_noweighedEdge(g);
		if (g.hasCircle())
		{
			cout << "has circle!\n";
			return 0;
		}

		//throw new.....
		//throw enable_loop;
	}

	if (head && tail)
	{
		DFSHeadTailGraph graph(core.wordset_size);
		core.insert_weighedEdge(graph);
		core.setHead(graph, head);
		core.setHeadTail(graph, tail);
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//输出
		core.getresult(result, ans);
		return ans.size();

	}
	else if (head)
	{
		DFSHeadGraph graph(core.wordset_size);
		core.insert_weighedEdge(graph);
		core.setHead(graph, head);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//输出
		core.getresult(result, ans);
		return ans.size();
	}
	else if (tail)
	{
		DFSHeadGraph graph(core.wordset_size);
		//反向建图
		core.insert_weighedReverseEdge(graph);
		core.setTail(graph, tail);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		//反转
		reverse(ans.begin(), ans.end());
		core.getresult(result, ans);
		return ans.size();
	}
	else
	{
		DFSGraph graph(core.wordset_size);
		core.insert_weighedEdge(graph);
		graph.hasCircle();
		vector<int> ans = graph.getAnsChain();
		if (ans.size() < 2)
			return 0;
		core.getresult(result, ans);
		return ans.size();
	}

	return 0;
}





