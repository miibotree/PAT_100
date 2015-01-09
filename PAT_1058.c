//PAT_1058
//Miibotree
//2015.1.9
#include <stdio.h>

typedef struct{
	int a;
	int b;
	int c;
}number;

int main(){
	number x, y, z;
	int cz = 0, cy = 0;//进位标记
	while(scanf("%d.%d.%d", &x.a, &x.b, &x.c) != EOF)
	{
		scanf("%d.%d.%d", &y.a, &y.b, &y.c);
		z.c = x.c + y.c;
		if (z.c >= 29)
		{
			cz = 1;
			z.c -= 29;
		}
		z.b = x.b + y.b + cz;
		if (z.b >= 17)
		{
			cy = 1;
			z.b -= 17;
		}
		z.a = x.a + y.a + cy;
		printf("%d.%d.%d\n", z.a, z.b, z.c);
	}
	return 0;
}