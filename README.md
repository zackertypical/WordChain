# WordChain


#### 参数约定


参数名字|	参数意义|	范围限制|	用法示例
-----|--|--|--|
-w|	需要求出单词数量最多的单词链|	绝对或相对路径|	示例：Wordlist.exe -w input.txt [表示从input.txt中读取单词文本，计算单词数量最多的单词链]
-c|	需要求出字母数量最多的单词链|	绝对或相对路径|	示例：Wordlist.exe -c input.txt [表示从input.txt中读取单词文本，计算字母数量最多的单词链]
-h|	指定单词链首字母|	a-z,A-Z	|示例：Wordlist.exe -h a -w input.txt [表示从input.txt中读取单词文本，计算满足首字母为a的、单词数量最多的单词链]
-t|	指定单词链尾字母|	a-z,A-Z	|示例：Wordlist.exe -t a -c input.txt [表示从input.txt中读取单词文本，计算满足尾字母为a的、字母数量最多的单词链]
-r|	允许单词文本中隐含单词环|	|	示例：Wordlist.exe -r -w| input.txt [表示从input.txt中读取单词文本，计算单词数量最多的单词链，即使单词文本中隐含单词环也需要求解]



#### GUI

bin内打开WordChainGUI.exe
