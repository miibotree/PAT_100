//PAT_1035
//Miibotree
//2015.1.8
#include <stdio.h>
#include <string.h>

typedef struct _info{
	char name[11];
	char pass[11];
	int modify;
}info;

int Change(info *x);

int main()
{
	info list[1001];
	int cnt = 0;
	int n = 0;
	while(scanf("%d", &n) != EOF)
	{
		cnt = 0;
		for(int i = 0; i < 1001; i++)
			list[i].modify = 0;

		for(int i = 0; i < n; i++)
		{
			scanf("%s %s", list[i].name, list[i].pass);
			Change(&list[i]);
			if (list[i].modify == 1)
				cnt++;
		}

		if (n == 1)//n=1 无论如何都输出下面这句话不改变密码
			printf("There is 1 account and no account is modified\n");
		
		else
		{
			if (cnt == 0)//没有被修改过
				printf("There are %d accounts and no account is modified\n", n);
			else//被修改过
			{
				printf("%d\n", cnt);
				for(int i = 0; i < n; i++)
				{
					if (list[i].modify == 1)
						printf("%s %s\n", list[i].name, list[i].pass);
				}	
			}
		}
	}
	return 0;
}

int Change(info *x)
{
	int pass_len = strlen(x->pass);
	for(int i = 0; i < pass_len; i++)
	{
		switch(x->pass[i])
		{
			case '1':
				x->pass[i] = '@';
				x->modify = true;
				break;
			case '0':
				x->pass[i] = '%';
				x->modify = true;
				break;
			case 'l':
				x->pass[i] = 'L';
				x->modify = true;
				break;
			case 'O':
				x->pass[i] = 'o';
				x->modify = true;
				break;
		}
	}
	return 0;
}