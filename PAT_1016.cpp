//PAT_1016. Phone Bills (25)
//Miibotree
//2015.2.15
//模拟题,账单模拟
//使用sort来排序分类，同时注意on-line与off-line的匹配
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

struct List
{
	char name[21];
	int month;
	int day;
	int hour;
	int minute;
	char tag[10];
	float sum;//总价格
}l[1001];

int rate[24];
float moneyAll = 0;
float money = 0;
int t;

bool cmp(List a, List b)
{
	int tmp = strcmp(a.name, b.name);
	if(tmp != 0)
		return tmp < 0;
	if(a.day != b.day)
		return a.day < b.day;
	if(a.hour != b.hour)
		return a.hour < b.hour;
	if(a.minute != b.minute)
		return a.minute < b.minute;
}

int check(int st, int n)
{
	char name[21];
	bool flag = false, out = false;
	strcpy(name, l[st].name);
	for(int i = st; i < n; ++i)
	{
		if(strcmp(l[i].name, name) == 0)//姓名相等
		{
			if(l[i].tag[1] == 'n')//on-line
				flag = true;
			else if(l[i].tag[1] == 'f' && flag)
			{
				flag = false;
				out = true;
			}
		}
		else
			break;
	}
	return out;
}

//看清题目说法：计算钱时(cents/minute)
//The rate structure consists of a line with 24 non-negative integers 
//denoting the toll (cents/minute) from 00:00 - 01:00, 
//the toll from 01:00 - 02:00, and so on for each hour in the day. 
void checkMoney(List st, List en)
{
	List r;  
    r.day= st.day;  
    r.hour = st.hour;  
    r.minute = st.minute;  
    t = 0;  
    money = 0;  
    for(; r.day < en.day || r.hour < en.hour || r.minute < en.minute; )  
    {  
        money+=rate[r.hour];  
        ++t;  
        ++r.minute;  
        if(r.minute>=60)  
        {  
            r.minute=0;  
            ++r.hour;  
            if(r.hour>=24)  
            {  
                r.hour=0;  
                ++r.day;  
            }  
        }  
    }  
    money/=100;  
}

int main()
{
	int n;
	for(int i = 0; i < 24; i++)
		scanf("%d", &rate[i]);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d:%d %s", l[i].name, &l[i].month, &l[i].day,
				&l[i].hour, &l[i].minute, l[i].tag);
	}
	sort(l, l+n, cmp);//按照名字排序
	int i = 0, out;
	while(i < n)
	{
		out = check(i, n);//判断一下有没有on off对
		if(out)
		{
			List r;
			char name[21];
			int flag = false;//当出现on时，flag变为true,期待off
			moneyAll = 0;
			printf("%s %02d\n", l[i].name, l[i].month);
			strcpy(name, l[i].name);
			for(; strcmp(name, l[i].name) == 0; i++)//姓名相同
			{
				if(l[i].tag[1] == 'n')
				{
					r.day = l[i].day;
					r.hour = l[i].hour;
					r.minute = l[i].minute;
					flag = true;
				}
				else if (l[i].tag[1] == 'f' && flag)
				{
					flag = false;
					printf("%02d:%02d:%02d %02d:%02d:%02d", 
						r.day, r.hour, r.minute, l[i].day, l[i].hour, l[i].minute);
					checkMoney(r, l[i]);
					printf(" %d $%.2f\n", t, money);
					moneyAll +=money;
				}
			}
			printf("Total amount: $%.2f\n", moneyAll);
		}
		else
			++i;
	}
	return 0;
}
