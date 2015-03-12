//PAT_1060.Are They Equal (25)
//2015.3.2
//使用string来操作减少代码量
//思路：0.000a1a2a3...
// b1b2b3.a1a2a3
//step1:去掉前导的0，判断去掉前导0之后的首位是否是 . ，如果是，则属于第一种情况，
//		如果不是，则属于第二种情况
//step2：计算指数，如果是第一种情况，每去掉小数点后面的一个0，指数-1，知道出现非0位或者长度到了
//				   如果是第二种情况，寻找小数点，每向右寻找一位，指数加1
//step3:计算底数，需要考虑补0的情况
//step4：特殊情况，有可能整个数就是0，比如00000.000000000这种special case需要特殊处理
#include <iostream>
#include <string>
using namespace std;

int n;
string deal(string s, int &e)
{
	int k = 0;//string的下标
	while(s.length() > 0 && s[0] == '0')//去掉前导的0
	{
		s.erase(s.begin());
	}
	if(s[0] == '.')//第一种情况
	{
		s.erase(s.begin());//去掉小数点
		while(s.length() > 0 && s[0] == '0')//去掉小数点后面的0的同时计算指数
		{
			s.erase(s.begin());
			e--;
		}
	}
	else//第二种情况
	{
		while(k < s.length() && s[k] != '.')//寻找小数点的同时计算指数
		{
			k++;
			e++;
		}
		if(k < s.length())//碰到了小数点
			s.erase(s.begin() + k);//移除小数点
	}
	if(s.length() == 0)
		e = 0;//这个数是0
	int num = 0;
	k = 0;
	string res;
	while(num < n)
	{
		if(k < s.length())
			res += s[k++];
		else
			res += '0';
		num++;
	}
	return res;
} 

int main()
{
	string s1, s2, s3, s4;
	int e1 = 0, e2 = 0;
	cin>>n>>s1>>s2;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e1)
		cout<<"YES "<<"0."<<s3<<"*10^"<<e1<<endl;
	else
		cout<<"NO "<<"0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
	return 0;
}