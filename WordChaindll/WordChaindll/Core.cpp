#include "stdafx.h"
#include "Core.h"


//字母异常
//开新内存异常

char Core::alpha_to_lower(char  ch)noexcept(false)
{
	if((ch < -1)||(ch > 255))
		throw exception(m_word_error);
	if (!isalpha(ch))
		throw exception(m_word_error);
	return ch |= 32;
}

void Core::insertChain(char * words[], int len)
{
	//使用set去重
	set<string> word_set;
	string str;
	for (int i = 0; i < len; i++)
	{
		str = "";
		for (int j = 0; words[i][j] != '\0'; j++)
		{
			str.push_back(alpha_to_lower(words[i][j]));
		}
		if(str!="")
			word_set.insert(str);
	}
	wordset_size = word_set.size();
	// 留出开头空字符串
	wordchain.push_back("");
	wordchain.insert(wordchain.begin() + 1, word_set.begin(), word_set.end());
}

void Core::print_wordchain()
{
	vector<string>::iterator it;
	int i = 0;
	for (it = wordchain.begin(); it != wordchain.end(); it++)
	{
		cout << i++ << " " <<*it << endl;
	}
	cout << endl;
}


void Core::insert_noweighedEdge(DFSGraph &graph)
{
	for (int i = 1; i <= wordset_size; i++)
	{
		graph.insertEdge(0, i);
		graph.changeVecWeigh(i, 1);
	}
	for (int i = 1; i <= wordset_size; i++)
		for (int j = 1; j <= wordset_size; j++)
			if (i != j)
			{
				//string str1 = wordchain[i];
				//string str2 = wordchain[j];
				if ((wordchain[i][wordchain[i].size()-1]) == wordchain[j][0])
				{
					graph.insertEdge(i, j);
				}

			}
}

void Core::insert_noweighedReverseEdge(DFSGraph &graph)
{
	for (int i = 1; i <= wordset_size; i++)
	{
		graph.insertEdge(0, i);
		graph.changeVecWeigh(i, 1);
	}
	for (int i = 1; i <= wordset_size; i++)
		for (int j = 1; j <= wordset_size; j++)
			if (i != j)
			{
				//string str1 = wordchain[i];
				//string str2 = wordchain[j];
				//if (*str1.begin() == *(str2.end() - 1))
				if(wordchain[i][0]==wordchain[j][wordchain[j].length()-1])
				{
					graph.insertEdge(i, j);
				}

			}
}


void Core::setTail(DFSHeadGraph &graph, char tail)
{
	for (int i = 1; i <= wordset_size; i++)
	{
		//string str = wordchain[i];
		if (wordchain[i][wordchain[i].length()-1] == tail)
		{
			graph.setHeadSingle(i);
		}
	}
}

void  Core::setHeadTail(DFSHeadTailGraph &graph, char tail)
{
	for (int i = 1; i <= wordset_size; i++)
	{
		//string str = wordchain[i];
		if (wordchain[i][wordchain[i].length() - 1] == tail)
		{
			graph.setTailSingle(i);
		}
	}
}



void  Core::setHead(DFSHeadGraph &graph, char head)
{
	for (int i = 1; i <= wordset_size; i++)
	{
		//string str = wordchain[i];
		if (wordchain[i][0] == head)
		{
			graph.setHeadSingle(i);
		}
	}
}


void Core::insert_weighedEdge(DFSGraph &graph)
{
	//节点0到所有的边的权重是该单词的长度
	for (int i = 1; i <= wordset_size; i++)
	{
		graph.changeVecWeigh(i,wordchain[i].size());
		graph.insertEdge(0, i);
	}

	for (int i = 1; i <= wordset_size; i++)
		for (int j = 1; j <= wordset_size; j++)
			if (i != j)
			{
				//string str1 = wordchain[i];
				//string str2 = wordchain[j];
				//if (*(str1.end() - 1) == *str2.begin())
				if(wordchain[i][wordchain[i].length()-1]==wordchain[j][0])
				{
					graph.insertEdge(i, j);
				}

			}
}

void Core::insert_weighedReverseEdge(DFSGraph &graph)
{
	//节点0到所有的边的权重是该单词的长度
	for (int i = 1; i <= wordset_size; i++)
	{
		graph.changeVecWeigh(i, wordchain[i].size());
		graph.insertEdge(0, i);
	}

	for (int i = 1; i <= wordset_size; i++)
		for (int j = 1; j <= wordset_size; j++)
			if (i != j)
			{
				//string str1 = wordchain[i];
				//string str2 = wordchain[j];
				//if (*str1.begin() == *(str2.end() - 1))
				if(wordchain[i][0]==wordchain[j][wordchain[j].size()-1])
				{
					graph.insertEdge(i, j);
				}

			}
}


void Core::getresult(char *result[],vector<int>& ans)
{
	string str;
	unsigned int i = 0;
	try {
		for (i = 0; i < ans.size(); i++)
		{
			str = wordchain[ans[i]];
			//动态内存分配
			result[i] = new char[str.size() + 1];
			strcpy(result[i], str.c_str());
			//str.copy(result[i], str.size(), 0);
			*(result[i] + str.size()) = '\0';
			cout << str << endl;
		}
	}
	catch (bad_alloc &e)
	{
		for (unsigned int j = 0; j < i; j++)
		{
			delete[]result[j];
		}
		ans.resize(0);
		cout <<"Error on Memory\n"<< e.what()<<endl;
	}
	
}



