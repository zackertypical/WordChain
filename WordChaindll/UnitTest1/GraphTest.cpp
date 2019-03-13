#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSHeadTailGraph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GraphTest
{
	TEST_CLASS(GraphTest)
	{
	public:

		TEST_METHOD(TestBaseGraph)
		{
			BaseGraph g(3);
			Assert::AreEqual(3, g.getVertexNum());
			Assert::AreEqual(0, g.getEdgeNum());
			g.insertEdge(1, 2);
			Assert::AreEqual(1, g.getEdgeNum());
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
			DFSHeadTailGraph g(4);
			for (int i = 1; i <= 4; i++)
			{
				g.changeVecWeigh(i, 1);
			}
			g.setHeadSingle(3);
			g.setTailSingle(1);
			g.insertEdge(3, 2);
			g.insertEdge(2, 1);
			Assert::AreEqual(2, g.getEdgeNum());
			vector<int> ans = g.getAnsChain();
			Assert::AreEqual(3, (int)ans.size());
		}
		TEST_METHOD(LoopGraph)
		{
			DFSGraph g(4);
			for (int i = 1; i <= 4; i++)
			{
				g.changeVecWeigh(i, 1);
			}
			g.insertEdge(3, 4);
			g.insertEdge(4, 3);

			Assert::AreEqual(true,g.hasCircle());

		}

	};
}