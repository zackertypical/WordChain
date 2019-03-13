#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSHeadTailGraph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExceptionTest
{
	TEST_CLASS(ExceptionTest)
	{
	public:

		TEST_METHOD(Head_Tail_insert_exception)
		{
			try
			{
				DFSHeadTailGraph g(1);
				g.setTailSingle(3);
			}
			catch (exception &e)
			{
				Assert::AreEqual(tail_out_of_range_error, e.what());
			}
		}
		TEST_METHOD(Head_insert_exception)
		{
			try
			{
				DFSHeadGraph g(1);
				g.setHeadSingle(2);
			}
			catch (exception &e)
			{
				Assert::AreEqual(head_out_of_range_error, e.what());
			}

		}
		TEST_METHOD(Vertex_insert_edge_outofrange)
		{
			try
			{
				DFSGraph g(3);
				g.insertEdge(5, 6);
			}
			catch (exception &e)
			{
				Assert::AreEqual(edge_out_of_range_error, e.what());
			}
		}
		TEST_METHOD(Vertex_change_weight_outofrange)
		{
			try
			{
				DFSGraph g(3);
				g.changeVecWeigh(4, 8);
			}
			catch (exception &e)
			{
				Assert::AreEqual(vertex_out_of_range_error, e.what());
			}
		}
		TEST_METHOD(Core_words_unrecognized)
		{
			try
			{
				Core core;
				char *words[3] = { "aa123","32432","333" };
				core.insertChain(words, 3);
			}
			catch (exception &e)
			{
				Assert::AreEqual(m_word_error, e.what());
			}
		}

		TEST_METHOD(Interface_check_loop)
		{
			try
			{
				char *words[2] = { "abb","baa" };
				char *result[2];
				int ans = gen_chain_word(words, 2, result, 0, 0, false);
				Assert::AreEqual(ans, 0);

			}
			catch (exception &e)
			{
				Assert::AreEqual(m_loop_error, e.what());
			}
		}
		TEST_METHOD(Interface_check_head_parameter)
		{
			try
			{
				checkParameter(10, 'A', 0);

			}
			catch (exception &e)
			{
				Assert::AreEqual(m_headchar_error, e.what());
			}
		}
		TEST_METHOD(Interface_check_tail_parameter)
		{
			try
			{
				checkParameter(10, 0, 1);

			}
			catch (exception &e)
			{
				Assert::AreEqual(m_tailchar_error, e.what());
			}
		}

		TEST_METHOD(Interface_check_len_parameter)
		{
			try
			{
				checkParameter(1000000, 0, 1);

			}
			catch (exception &e)
			{
				Assert::AreEqual(m_len_error, e.what());
			}
		}

	};
}