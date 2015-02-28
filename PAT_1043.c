//PAT_1043. Is It a Binary Search Tree (25)
//Miibotree
//2015.1.16

//1.建立二叉排序树
//2.建立该二叉排序树的镜像树
//3.判断该序列是不是二叉排序树或者镜像树的前序遍历
//4.若是，则输出对应一种情况的后序遍历
#include <stdio.h>

struct Node
{
    Node *lchild;
    Node *rchild;
    int value;
}Tree[2002];

int loc;
int BST_pre[1001];
int MBST_pre[1001];
int *pre;
int *cnt;
int cnt1, cnt2;

void PreOrder(Node *T)
{
    //访问根节点
    pre[(*cnt)++] = T->value; 
    if (T->lchild != NULL)
        PreOrder(T->lchild);
    if (T->rchild != NULL)
        PreOrder(T->rchild);
}
int sum = 1;
void PostOrder(Node *T, int n)
{
    if (T->lchild != NULL)
        PostOrder(T->lchild, n);
    if (T->rchild != NULL)
        PostOrder(T->rchild, n);
    if (sum < n)
    {
        printf("%d ", T->value);//注意最后的空格
        sum++;
    }
    else
        printf("%d\n", T->value);
}

Node *Create()
{
    Tree[loc].lchild = NULL;
    Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

Node *Insert1(Node *T, int x)
{
    if (T == NULL)
    {
        T = Create();
        T->value = x;
        return T;
    }
    else if(x < T->value)
        T->lchild = Insert1(T->lchild, x);
    else if (x >= T->value)
        T->rchild = Insert1(T->rchild, x);
    return T;
}

Node *Insert2(Node *T, int x)
{
    if (T == NULL)
    {
        T = Create();
        T->value = x;
        return T;
    }
    else if(x >= T->value)
        T->lchild = Insert2(T->lchild, x);
    else if (x < T->value)
        T->rchild = Insert2(T->rchild, x);
    return T;
}

int Judge(Node *T1, Node *T2, int *a, int n)
{
    int flag1 = 1, flag2 = 1;
    cnt1 = 0;
    cnt = &cnt1;
    pre = BST_pre;
    PreOrder(T1);
    for (int i = 0 ; i < n; i++)
    {
        if (BST_pre[i] != a[i])
        {
            flag1 = 0;
            break;
        }
    }

    cnt2 = 0;
    cnt = &cnt2;
    pre = MBST_pre;
    PreOrder(T2);
    for (int i = 0 ; i < n; i++)
    {
        if (MBST_pre[i] != a[i])
        {
            flag2 = 0;
            break;
        }
    }
    if (flag1 == 1)
        return 1;
    else if (flag2 == 1)
        return 2;
    else
        return 0;
}


int main()
{
    int n = 0;
    int a[1001];
    while (scanf("%d", &n) != EOF)
    {
        Node *T1 = NULL;
        Node *T2 = NULL;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            T1 = Insert1(T1, a[i]);//建立BST
            T2 = Insert2(T2, a[i]);//建立MBST
        }

        int flag = Judge(T1, T2, a, n);
        if (flag == 1)
        {
            printf("YES\n");
            sum = 1;
            PostOrder(T1, n);
        }
        else if (flag == 2)
        {
            printf("YES\n");
            sum = 1;
            PostOrder(T2, n);
        }
        else
            printf("NO\n");
    }
}