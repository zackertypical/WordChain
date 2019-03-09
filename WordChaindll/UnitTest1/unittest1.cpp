#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char *words[10] = { "abc","cbb","bmm","mcd","daa" };
			char *result[1000];
			int ans = gen_chain_word(words,5 ,result, 'b', 0, 1);
			Assert::AreEqual( 5,ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual(str,(string) "bmmmcddaaabccbb");
		}
		TEST_METHOD(TestMethod2)
		{
			char *words[100] = { "abc","cbb","bmm","mcd","dak","kao","jm","zd","lq","qq" };
			char *result[1000];
			int ans = gen_chain_char(words,10, result, 0, 0, 1);
			Assert::AreEqual(29,ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			//Assert::AreEqual(str, (string) "bmmmcddaaabccbb");
		}
		TEST_METHOD(TestMethod3)
		{
			DFSGraph g(10);
		}
		TEST_METHOD(TestMethod4)
		{
			DFSGraph g(10);
		}
	};
}