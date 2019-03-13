#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSHeadTailGraph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{
	TEST_CLASS(GraphTest)
	{
	public:

		TEST_METHOD(TestDFSGraph)
		{
			try
			{
				DFSHeadTailGraph g(1);
				g.setTailSingle(1);
				g.insertEdge(1, 2);
			}
			catch (exception &e)
			{
				cout << e.what();
			}
		}
		TEST_METHOD(TestHeadGraph)
		{
			DFSHeadGraph g(4);
			for(int i = 1;i <=4 ;i++)
			{
				g.changeVecWeigh(i, 1);
			}
			g.setHeadSingle(3);
			g.insertEdge(3, 4);
			vector<int> ans = g.getAnsChain();
			Assert::AreEqual(2,(int) ans.size());

		}
		TEST_METHOD(TestHeadTailGraph)
		{
			DFSGraph g(10);
		}
		TEST_METHOD(TestMethodN)
		{
			DFSGraph g(10);
		}
	};
}