//PAT_1051 Pop Sequence
//Miibotree
//2015.1.15
//这是一道练习栈的题目

#include <stack>
#include <stdio.h>

using namespace std;
stack<int> s;

int main()
{
    int m, n, k;
    int a[1001];
    while (scanf("%d%d%d", &m, &n, &k) != EOF)
    {
        for (int i = 0; i < k; i++)//总共有k组数据
        {
            for (int j = 0; j < n; j++)
                scanf("%d", &a[j]);
            bool flag = true;
            int cur = 1;//游标
            s.push(cur);
            int k = 0;
            while(k < n)
            {
                int tmp = a[k];
                if (tmp > cur)//不断压栈
                {
                    for (int p = cur+1; p <= tmp; p++)
                        s.push(p);
                    cur = tmp;
                    if (s.size() > m)
                        flag = false;
                }
                else
                {
                    if (s.top() != tmp)
                        flag = false;
                }
                k++;
                s.pop();
            }
            if (flag)//说明是正常退出
                printf("YES\n");
            else
                printf("NO\n");
        }                   
    }
    return 0;
}