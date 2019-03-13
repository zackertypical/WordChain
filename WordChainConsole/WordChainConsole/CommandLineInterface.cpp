

#include "stdafx.h"
#include "WordChaindll.h"

#define MAX 10005
#define CHARLEN 1000

static const char* m_file_error = "File open error!";
static const char* m_command_error = "Command error!";
static const char* m_maxword_error = "Words out of range 10000!";


int read_file(char *filename,char*words[])
{
	string str = "";
	ifstream fin(filename);
	if (!fin)
	{
		throw exception(m_file_error);
	}
	char ch;
	int i = 0;
	int j = 0;
	words[i] = new char[CHARLEN];
	while ((ch = fin.get()) != EOF)
	{
		if (isalpha(ch))
		{
			words[i][j] = ch;
			j++;
		}
		else
		{
			if (j == 0)
				continue;
			words[i][j] = '\0';
			i++;
			if (i >= MAX - 5)
				throw exception(m_maxword_error);
			words[i] = new char[CHARLEN];
			j = 0;
		}
	}
	words[i][j] = '\0';
	i++;

	//输出
	//for (j = 0;j < i;j++)
	{
		//cout << words[j] << endl;
	}
	cout << endl;
	return i;

}

void output_file(char *filename, char*results[],int len)
{
	ofstream fout(filename);
	if (!fout)
	{
		throw exception(m_file_error);
	}
	for (int i = 0; i < len; i++)
	{
		fout << results[i] << endl;
	}

}


void deal_command(int argc,char *argv[],char &head,char &tail,char* &filename,bool &findMaxChar,bool &findMaxLen,bool &enable_loop)
{
	int opt = 1;
	for (opt = 1; opt < argc; opt++)
	{
		if (opt == argc - 1)
		{
			filename = argv[opt];
			break;
		}

		if(argv[opt][0]!='-')
			throw (exception(m_command_error));
		
		switch (argv[opt][1])
		{
			case 'w':
				if (findMaxChar || findMaxLen)
					throw(exception(m_command_error));
				findMaxLen = true;
				break;
			case 'c':
				if (findMaxChar || findMaxLen)
					throw(exception(m_command_error));
				findMaxChar = true;
				break;
			case 'r':
				if (enable_loop)
					throw(exception(m_command_error));
				else
					enable_loop = true;
				break;
			case 'h':
				if (head)
					throw(exception(m_command_error));
				else
				{
					opt++;
					head = argv[opt][0];
				}
				break;
			case 't':
				if (tail)
					throw(exception(m_command_error));
				else
				{
					opt++;
					tail = argv[opt][0];
				}
				break;
			default:
				throw(exception(m_command_error));
				break;
		}
			
		
	}
}


int main(int argc,char *argv[])
{
	char *words[MAX];
	char *result[MAX];
	int len = 0;

	bool findMaxChar = false;
	bool findMaxLen = false;
	char tail = 0;
	char head = 0;
	bool enable_loop = false;
	char *filename;


	//解析命令行
	try
	{
		deal_command(argc, argv, head, tail, filename, findMaxChar, findMaxLen, enable_loop);
		len = read_file(filename, words);
		//len = read_file("../Debug/m10.txt", words);
		int ans;
		if (findMaxChar)
		{
			ans = gen_chain_char(words, len, result, head, tail, enable_loop);
		}
		else{
			ans = gen_chain_word(words, len, result, head, tail, enable_loop);
		}
		//ans = gen_chain_word(words, len, result,0,0,1);
		//ans = gen_chain_char(words, len, result, 'a',0, 1);
		if (ans < 2)
			cout << "no chain found" << endl;
		output_file("solution.txt", result, ans);
	}
	catch(exception &e)
	{
		cout << "Error." << e.what();
	}

	//释放内存
	for (int i = 0; i < len; i++)
	{
		if (words[i])
			delete[]words[i];
		if(result[i])
			delete[]result[i];
	}

	return 0;
}