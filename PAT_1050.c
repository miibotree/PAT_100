//PAT_1050 String Subtraction  20
//Miibotree
//2015.1.9
//思路： 时间限制10ms hash

#include <stdio.h>
#include <string.h>

int main(){
  char s1[10001], s2[10001];
  int i = 0;
  int len1 = 0, len2 = 0;
  while(gets(s1))
  {
      gets(s2);
      int alphabet[256] = {0};
      len1 = strlen(s1);//注意这里求长度必须先求出来 不能放到for循环里面去求 
      len2 = strlen(s2);//不然每次for循环都会求一次长度，时间复杂度大大增加而不能AC
          
      for (i = 0; i < len2; i++)
          alphabet[s2[i]] = 1;
      for (i = 0; i < len1; i++)
      {
          if(alphabet[s1[i]] == 0)
              printf("%c", s1[i]);
      }
      printf("\n");
  }
  return 0;
}