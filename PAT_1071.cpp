//1071. Speech Patterns (25)
//Miibotree
//2015.1.31
//继续训练STL map和string的使用

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool isalp(char a)
{
	if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z' || a >= '0' && a <= '9')
		return true;
	else
		return false;
}

int main()
{
	string s, word;
	map<string, int> count;
	map<string, int>::iterator it, tmp;
	int start = 0, end = 0;

	while(getline(cin, s))
	{
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		start = 0;end = 0;
		while(start < s.length())
		{
			start = end;
			while(!isalp(s[start]) && start < s.length())
				start++;//找到单词的开始位置
			end = start;
			while(isalp(s[end]) && end < s.length())
				end++;
			if(start != end)
			{
				word = s.substr(start, end-start);
				if(count.find(word) == count.end())
					count[word] = 1;
				else
					count[word]++;
			}
 		}
		int max = -1;
		for(it = count.begin(); it != count.end(); it++)
		{
			if(it->second > max)
			{
				max = it->second;
				tmp = it;
			}
		}
		cout<<tmp->first<<" "<<tmp->second<<endl;
	}
	return 0;
}