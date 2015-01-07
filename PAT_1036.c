//PAT_1036
//Miibotree
//2015.1.7

#include <stdio.h>

typedef struct _info
{
	char name[11];//Notice that the character size should be at least 11  
	char gender;
	char ID[11];
	int grade;
}info;

info sample[10000];

int main()
{
	int n = 0;
	int girl_num = 0, boy_num = 0;
	int boy_lowest_grade = 100, girl_highest_grade = 0;
	int boy_lowest_num = 0, girl_highest_num = 0;

	while (scanf("%d", &n) != EOF)
	{
		girl_num = 0, boy_num = 0;
		boy_lowest_grade = 100; girl_highest_grade = 0;
		boy_lowest_num = 0; 	girl_highest_num = 0;
		
		for (int i = 0; i < n; i++)
			scanf("%s %c %s %d", sample[i].name, &sample[i].gender,sample[i].ID, &sample[i].grade);
		
		for (int i = 0; i < n; i++)
		{
			if (sample[i].gender == 'M')//boy
			{
				boy_num++;
				if (sample[i]. grade < boy_lowest_grade)
				{
					boy_lowest_grade = sample[i].grade;
					boy_lowest_num = i;
				}
			}
			else//girl
			{
				girl_num++;
				if (sample[i]. grade > girl_highest_grade)
				{
					girl_highest_grade = sample[i].grade;
					girl_highest_num = i;
				}
			}
		}

		if (girl_num == 0)
			printf("Absent\n");
		else
			printf("%s %s\n", sample[girl_highest_num].name, sample[girl_highest_num].ID);

		if (boy_num == 0)
			printf("Absent\n");
		else
			printf("%s %s\n", sample[boy_lowest_num].name, sample[boy_lowest_num].ID);
		
		if (girl_num == 0 || boy_num == 0)
			printf("NA\n");
		else
			printf("%d\n", sample[girl_highest_num].grade - sample[boy_lowest_num].grade);
	}

	return 0;
}