#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InterfaceTest
{		
	TEST_CLASS(InterfaceTest)
	{
	public:
		
		TEST_METHOD(LoopTest)
		{
			char *words[5] = { "aaaaaa","aaaaa","aaaa","aaa","aa" };
			char *result[6];
			int ans = gen_chain_word(words,5 ,result, 0, 0, true);
			Assert::AreEqual( 5,ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual(str,(string) "aaaaaaaaaaaaaaaaaaaa");
		}

		TEST_METHOD(RepeatedWordsTest)
		{
			char *words[4] = {"abcba","accac","cbbaa","abcba" };
			char *result[4];
			int ans = gen_chain_char(words,4, result, 0, 0, true);
			Assert::AreEqual(3,ans);
		}

		TEST_METHOD(NoAnswerTest)
		{
			char *words[4] = { "ac","de","fg","am" };
			char *result[4];
			int ans = gen_chain_word(words, 4, result, 0, 0, false);
			Assert::AreEqual(0, ans);
		}
		TEST_METHOD(noLoopTest)
		{
			char *words[4] = { "ab","bc","cd","da" };
			char *result[4];
			int ans = gen_chain_word(words, 4, result, 0, 0, false);
			Assert::AreEqual(0, ans);
		}
		TEST_METHOD(MaxCharTest)
		{
			char *words[4] = { "abbbb","abbb","bc","cd" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 0, 0, false);
			Assert::AreEqual(3, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "abbbbbccd",str);
		}
		TEST_METHOD(HeadTest_noLoop)
		{
			char *words[10] = { "cddd","dddd","aakkkc","bad","am","mc" };
			char *result[4];
			int ans = gen_chain_char(words, 6, result, 'a', 0, false);
			Assert::AreEqual(3, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "aakkkccddddddd", str);

			ans = gen_chain_word(words, 6, result, 'a', 0, false);
			str = "";
			Assert::AreEqual(4, ans);
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "ammccddddddd", str);

		}
		TEST_METHOD(TailTest_noLoop)
		{
			char *words[10] = { "kzz","kdd","accccck" ,"am","mk"};
			char *result[4];
			int ans = gen_chain_char(words, 5, result, 0, 'z', false);
			Assert::AreEqual(2, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "accccckkzz", str);

			ans = gen_chain_word(words, 5, result, 0, 'z', false);
			Assert::AreEqual(3, ans);
			str = "";
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "ammkkzz", str);


			
		}
		TEST_METHOD(HeadTailTest_noLoop)
		{
			char *words[10] = { "abcd","demmmfg","gkbb","bmmm","mjjj","jooo","dz","zl","lg" };
			char *result[6];
			int ans = gen_chain_char(words, 9, result, 'd', 'j', false);
			Assert::AreEqual(4, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "demmmfggkbbbmmmmjjj", str);

			ans = gen_chain_word(words, 9, result, 'd', 'j', false);
			Assert::AreEqual(6, ans);
			str = "";
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "dzzllggkbbbmmmmjjj", str);
		}

		TEST_METHOD(HeadTest_Loop)
		{
			char *words[4] = { "cddd","dddc","aac","bad" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 'a', 0, true);
			Assert::AreEqual(3, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "aaccddddddc", str);
		}
		TEST_METHOD(TailTest_Loop)
		{
			char *words[4] = { "kzz","kdd","ak","ka" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 0, 'z', true);
			Assert::AreEqual(3, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "kaakkzz", str);
		}
		TEST_METHOD(HeadTailTest_Loop)
		{
			char *words[13] = { "abcd","defg","gkbb","bmmm","mjjj","jooo" ,"bg","gb"};
			char *result[6];
			int ans = gen_chain_word(words, 8, result, 'd', 'j', true);
			Assert::AreEqual(6, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "defggkbbbggbbmmmmjjj", str);
		}


	};
}