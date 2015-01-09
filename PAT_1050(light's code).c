#include<stdio.h>  
#include<string.h>  
const int MAX=10000;  
  
int main()  
{  
    int i,j,len1,len2;  
    char str1[MAX],str2[MAX];  
    //freopen("G:\\in.txt","r",stdin);  
    //freopen("G:\\our.txt","w",stdout);  
    while(gets(str1)){  
        gets(str2);  
        bool visited[MAX];  
        for(i=0;i<MAX;i++)  
            visited[i]=0;  
        len1=strlen(str1); len2=strlen(str2);  
        for(i=0;i<len2;i++)         //把 str[i]做下标 的都标记为true。  
            visited[str2[i]]=1;  
        for(i=0;i<len1;i++){       //把未被标记的 下标 输出。  
            if(visited[str1[i]]==0)  
                printf("%c",str1[i]);  
        }  
        printf("\n");  
    }  
    return 0;  
}  