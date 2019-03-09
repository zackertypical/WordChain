# WordChain


#### 参数约定


参数名字|	参数意义|	范围限制|	用法示例
-----|--|--|--|
-w|	需要求出单词数量最多的单词链|	绝对或相对路径|	示例：Wordlist.exe -w input.txt [表示从input.txt中读取单词文本，计算单词数量最多的单词链]
-c|	需要求出字母数量最多的单词链|	绝对或相对路径|	示例：Wordlist.exe -c input.txt [表示从input.txt中读取单词文本，计算字母数量最多的单词链]
-h|	指定单词链首字母|	a-z,A-Z	|示例：Wordlist.exe -h a -w input.txt [表示从input.txt中读取单词文本，计算满足首字母为a的、单词数量最多的单词链]
-t|	指定单词链尾字母|	a-z,A-Z	|示例：Wordlist.exe -t a -c input.txt [表示从input.txt中读取单词文本，计算满足尾字母为a的、字母数量最多的单词链]
-r|	允许单词文本中隐含单词环|	|	示例：Wordlist.exe -r -w| input.txt [表示从input.txt中读取单词文本，计算单词数量最多的单词链，即使单词文本中隐含单词环也需要求解]



#### PSP分析 

PSP2.1|	Personal Software Process Stages|预估耗时（分钟）|实际耗时（分钟）
---|--|--|--|
Planning|计划|
·Estimate|估计这个任务需要多少时间|60|60*2
Development|开发|57*60		
·Analysis| ·需求分析 (包括学习新技术)|8*60		
·Design Spec|	· 生成设计文档|4*60		
·Design Review|	· 设计复审 (和同事审核设计文档)|2*60	
·Coding Standard|	· 代码规范 (为目前的开发制定合适的规范)|1*60	
·Design|· 具体设计	|5*60	
·Coding|· 具体编码	|24*60	
·Code Review|· 代码复审|8*60		
·Test|· 测试（自我测试，修改代码，提交修改）|5*60		
Reporting|报告	|5*60	
·Test Report|· 测试报告|2*60		
·Size Measurement|	· 计算工作量|60		
·ostmortem & Process Improvement Plan|	· 事后总结, 并提出过程改进计划	|2*60	
| | 合计	|	

#### 第二阶段


1.Core接口的实现，以及你为Core模块设计的其他接口，并说明如何使用这些接口。

2.选择部分单元测试代码发布在博客中，并说明测试的函数，构造测试数据的思路。

3.将单元测试得到的测试覆盖率截图，发表在博客中。要求总体覆盖率到90%以上，否则单元测试部分视作无效。
