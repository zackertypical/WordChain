

#include "stdafx.h"
#include "ParameterException.h"


void checkParameter(int len, char head, char tail)noexcept(false)
{
	if (len > MAXLEN)
		throw exception(m_len_error);
	if(head!=0)
		if ((!isalpha(head))|| !islower(head))
			throw exception(m_headchar_error);
	if(tail!=0)
		if ((!isalpha(tail))|| !islower(tail))
			throw exception(m_tailchar_error);
}
