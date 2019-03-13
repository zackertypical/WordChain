#include "stdafx.h"

#include "../WordChaindll/WordChaindll.h"
#include "../WordChaindll/DFSGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InterfaceTest
{		
	TEST_CLASS(InterfaceTest)
	{
	public:
		
		TEST_METHOD(LoopTest1)
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
			int ans = gen_chain_char(words,4, result, 0, 0, 1);
			Assert::AreEqual(3,ans);
		}

		TEST_METHOD(NoAnswerTest)
		{
			char *words[4] = { "ac","de","fg","am" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 0, 0, 0);
			Assert::AreEqual(0, ans);
		}
		TEST_METHOD(UnableLoopTest)
		{
			char *words[4] = { "ab","bc","cd","da" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 0, 0, false);
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
		TEST_METHOD(HeadTest)
		{
			char *words[4] = { "cddd","dddd","aac","bad" };
			char *result[4];
			int ans = gen_chain_char(words, 4, result, 'a', 0, false);
			Assert::AreEqual(3, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "aaccddddddd", str);
		}
		TEST_METHOD(TailTest)
		{
			char *words[4] = { "kzz","kdd","ak" };
			char *result[4];
			int ans = gen_chain_char(words, 3, result, 0, 'z', false);
			Assert::AreEqual(2, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "akkzz", str);
		}
		TEST_METHOD(HeadTailTest)
		{
			char *words[6] = { "abcd","defg","gkbb","bmmm","mjjj","jooo" };
			char *result[6];
			int ans = gen_chain_char(words, 6, result, 'd', 'j', false);
			Assert::AreEqual(4, ans);
			string str;
			for (int i = 0; i < ans; i++)
			{
				str.append(result[i]);
			}
			Assert::AreEqual((string) "defggkbbbmmmmjjj", str);
		}
	};
}