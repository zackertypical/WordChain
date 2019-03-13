#pragma once
#ifdef WORDCHAINDLL_EXPORTS
#define WORDCHAIN_API __declspec(dllexport)
#else
#define WORDCHAIN_API __declspec(dllimport)
#endif

#include "stdafx.h"
#include "Core.h"
#include "ParameterException.h"



extern "C" WORDCHAIN_API int gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop);
extern "C" WORDCHAIN_API int gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop);