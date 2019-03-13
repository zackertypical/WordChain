
#pragma once
#include"stdafx.h"

#define MAXLEN 10000
static const char * m_headchar_error = "The Parameter \"head\" must be a-z.";
static const char * m_tailchar_error = "The Parameter \"tail\" must be a-z.";
static const char * m_len_error = "Len is too large,len must be less than 10000.";
static const char * m_loop_error = "Has circle! Must enable loop.";
static const char * m_word_error = "Words must be English.";
void checkParameter(int len, char head, char tail)noexcept(false);