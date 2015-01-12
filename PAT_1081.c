//PAT_1081
//Miibotree
//2015.1.12
//做这道题目的时候参照了别人的代码（人家的代码写的太简洁了！！）
//这里不需要特别注意正负号的问题，正负号归在分子部分，所以可以统一处理
//该题目是模拟题，模拟分数相加的方法

#include <stdio.h>  

long long gcd(long long x, long long y);
long long lcm(long long x, long long y);

long long a[100], b[100];  

int main(){  
    int n = 0;

    while (scanf("%d", &n) != EOF)
    {
        long long nume = 0, deno = 1, pre = 0;

        for (int i = 0; i < n; i++){
            scanf("%lld/%lld", &a[i], &b[i]);
            deno = lcm(deno, b[i]);//计算分母的最小公倍数
        }
        for (int i = 0; i < n; i++)        
             nume += deno / b[i] * a[i];

        pre = nume / deno;
        nume = nume % deno;

        //化简形式
        long long tmp = gcd(nume, deno);
        nume = nume / tmp;
        deno = deno / tmp;

        //输出
        if (pre == 0 && nume == 0)
            printf("0\n");
        else if (pre != 0 && nume == 0)
            printf("%lld\n", pre);
        else if (pre == 0 && nume != 0)
            printf("%lld/%lld\n", nume, deno);
        else
            printf("%lld %lld/%lld\n", pre, nume, deno);
    }
}  

long long gcd(long long x, long long y){  //最大公约数 递归的形式
    if (y == 0) 
        return x;  
    else 
        return gcd(y, x%y);  
}  

long long lcm(long long x, long long y){  //最小公倍数
    return x / gcd(x, y) * y;  //注意这里的细节 为了防止溢出 先除再乘
}
