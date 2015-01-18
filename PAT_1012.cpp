//PAT_1012.The Best Rank (23/25)
//Miibotree
//2015.1.18
//碰到了这个奇葩的问题。。。去掉注释就是段错误。。。
#include <stdio.h>
#include <algorithm>

using namespace std;

struct Info1{
  int C;
  int M;
  int E;
  int A;
  int ID;
}s1[1000001];

struct Info2{
  //int C;
  int Crank;
 // int M;
  int Mrank;
 // int E;
  int Erank;
 // int A;
  int Arank;
  int flag;
}s2[1000001];

bool cmp1(Info1 x, Info1 y)
{
  if (x.A != y.A)
    return(x.A > y.A);
}
bool cmp2(Info1 x, Info1 y)
{
  if (x.C != y.C)
    return(x.C > y.C);
}
bool cmp3(Info1 x, Info1 y)
{
  if (x.M != y.M)
    return(x.M > y.M);
}
bool cmp4(Info1 x, Info1 y)
{
  if (x.E != y.E)
    return(x.E > y.E);
}

void Echo(int t);

int main()
{
  int n, m;

  while (scanf("%d%d", &n ,&m) != EOF)
  {
    for (int i = 0; i < 1000000; i++)
    s2[i].flag = 0;

    int studentID, Cscore, Mscore, Escore, Ascore;
    for (int i = 0; i < n; i++)
    {
      scanf("%d%d%d%d", &studentID, &Cscore, &Mscore, &Escore);
      s1[i].ID = studentID;
      s1[i].C = Cscore;
      s1[i].M = Mscore;
      s1[i].E = Escore;
      s1[i].A = (Cscore + Mscore + Escore) / 3;
    }

    sort(s1, s1+n, cmp1);
    for(int i = 0; i < n; i++)
    {
      s2[s1[i].ID].Arank = i+1;
      //s2[s1[i].ID].A = s1[i].A;
      s2[s1[i].ID].flag = 1;
    }

    sort(s1, s1+n, cmp2);
    for(int i = 0; i < n; i++)
    {
      s2[s1[i].ID].Crank = i+1;
      //s2[s1[i].ID].C = s1[i].C;
    }

    sort(s1, s1+n, cmp3);
    for(int i = 0; i < n; i++)
    {
      s2[s1[i].ID].Mrank = i+1;
      //s2[s1[i].ID].M = s1[i].M;
    }

    sort(s1, s1+n, cmp4);
    for(int i = 0; i < n; i++)
    {
      s2[s1[i].ID].Erank = i+1;
      //s2[s1[i].ID].E = s1[i].E;
    }

    for (int i = 0; i < m; i++)
    {
      int t;
      scanf("%d", &t);
      Echo(t);
    }

  }
  return 0;
}

void Echo(int t)
{
  if (s2[t].flag == 0)
    printf("N/A\n");
  else
  {
    int rank = s2[t].Arank;
    char type = 'A';
    if (s2[t].Crank < rank)
    {
      rank = s2[t].Crank;
      type = 'C';
    }
    if (s2[t].Mrank < rank)
    {
      rank = s2[t].Mrank;
      type = 'M';
    }
    if (s2[t].Erank < rank)
    {
      rank = s2[t].Erank;
      type = 'E';
    }
    printf("%d %c\n", rank, type);
  }
}