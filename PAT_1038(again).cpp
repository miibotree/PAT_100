//PAT_1038. Recover the Smallest Number (30)
#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
string s[10001];
bool cmp(string a, string b)
{
	return a + b < b + a;
}
int main()
{
	int n;
	char str[10];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", str);
		s[i] = str;
	}
	sort(s, s+n, cmp);
	string ans;
	for(int i = 0; i < n; i++)
		ans += s[i];
	while(ans[0] == '0' && ans.size() > 1)
		ans.erase(ans.begin());
  	if(ans.size() == 0)//边界条件注意
         	cout<<0<<endl;
  	else
		cout<<ans<<endl;
	return 0;
}