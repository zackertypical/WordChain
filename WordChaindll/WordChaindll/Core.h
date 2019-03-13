#pragma once
#include "stdafx.h"
#include "DFSHeadTailGraph.h"
#include "ParameterException.h"


class Core
{
public:
	vector<string> wordchain;
	int wordset_size = 0;
	char alpha_to_lower(char  ch)noexcept(false);
	void insertChain(char * words[], int len);
	void Core::print_wordchain();
	void Core::insert_noweighedEdge(DFSGraph &graph);
	void Core::insert_noweighedReverseEdge(DFSGraph &graph);
	void Core::setTail(DFSHeadGraph &graph, char tail);
	void setHeadTail(DFSHeadTailGraph &graph, char tail);
	void Core::setHead(DFSHeadGraph &graph, char head);
	void Core::insert_weighedEdge(DFSGraph &graph);
	void Core::insert_weighedReverseEdge(DFSGraph &graph);
	void Core::getresult(char *result[], vector<int>& ans);

//public:
	//int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
	//int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
};
//对外提供两个接口





