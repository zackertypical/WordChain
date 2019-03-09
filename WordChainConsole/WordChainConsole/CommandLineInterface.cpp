

#include "stdafx.h"
#include "WordChaindll.h"

#define MAX 10005
#define CHARLEN 1000

int read_file(char *filename,char*words[])
{
	string str = "";
	ifstream fin(filename);
	if (!fin)
	{
		//todo :throw..
		cout << "文件无法打开"<<endl;
		return 0;
	}
		
	//freopen(filename, "r",stdin);
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
		//todo throw....
		cout << "无法写入" << endl;
		return;
	}
	for (int i = 0; i < len; i++)
	{
		fout << results[i] << endl;
	}

}


int main(int argc,char *argv[])
{
	char *words[MAX];
	char *result[MAX];
	int len;

	bool findMaxChar = false;
	bool findMaxLen = false;
	char tail = 0;
	char head = 0;
	bool enable_loop = false;
	char *filename;

	//解析命令行
	int opt = 1;
	int flag = false;

	for (opt = 1; opt < argc; opt++)
	{
		if (flag)
		{
			cout << "wrong format" << endl;
			break;
		}
		if (opt == argc - 1)
		{
			filename = argv[opt];
			break;
		}
		switch (argv[opt][0])
		{
			case '-':
			{
				switch (argv[opt][1])
				{
				case 'w':
					if (findMaxChar || findMaxLen)
						flag = true;
					else
						findMaxLen = true;
					break;
				case 'c':
					if (findMaxChar || findMaxLen)
						flag = true;
					else
						findMaxChar = true;
					break;
				case 'r':
					if (enable_loop)
						flag = true;
					else
						enable_loop = true;
					break;
				case 'h':
					if (head)
						flag = true;
					else
					{
						opt++;
						head = argv[opt][0];
					}
					break;
				case 't':
					if (head)
						flag = true;
					else
					{
						opt++;
						tail = argv[opt][0];
					}
					break;
				default:
					flag = true;
					break;
				}
			}

		}
	}
	//len = read_file(filename, words);
	len = read_file("testfile/aa.txt",words);
	if (flag)
	{
		cout << "wrong format" << endl;
		return 0;
	}
	int ans;
	/*if (findMaxChar)
	{
		ans = coreWordCompute.gen_chain_char(words, len, result, head, tail, enable_loop);
	}
	else{
		ans = coreWordCompute.gen_chain_word(words, len, result, head, tail, enable_loop);
	}*/
	ans = gen_chain_word(words, len, result,0,0, 0);
	
	if (ans < 2)
		cout << "no chain found" << endl;
	output_file("solution.txt", result,ans);

	//释放内存
	for (int i = 0; i < len; i++)
	{
		delete[]words[i];
		if(!result[i])
			delete[]result[i];
	}

	return 0;
		


}