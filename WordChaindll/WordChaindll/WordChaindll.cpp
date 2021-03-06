// WordChaindll.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "WordChaindll.h"



int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop) 
{
	try
	{
		checkParameter(len, head, tail);
		Core core;
		//去重预处理
		core.insertChain(words, len);
		//print
		//core.print_wordchain();
		//检测是否有环
		if (!enable_loop)
		{
			DFSGraph g(core.wordset_size);
			core.insert_noweighedEdge(g);
			if (g.hasCircle())
				throw exception(m_loop_error);//exception loop
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
	}
	catch (exception& e)
	{
		cout << "Error occurs!\n" << e.what() << endl;
	}
	
	return 0;
}

int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{

	try 
	{
		checkParameter(len, head, tail);
		Core core;
		core.insertChain(words, len);
		////打印
		//core.print_wordchain();
		//检测是否有环
		if (!enable_loop)
		{
			DFSGraph g(core.wordset_size);
			core.insert_noweighedEdge(g);
			if (g.hasCircle())
				throw exception(m_loop_error);//exception loop
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
	}
	

	catch (exception& e)
	{
		cout << "Error occurs!\n" << e.what() << endl;
	}

	return 0;
}





