//PAT_1006 Sign In and Sign Out
//Miibotree
//2015.1.7

#include <stdio.h>
#include <string.h>

typedef struct _time{
	int hour;
	int minute;
	int second;
}time;

typedef struct _node{
	char ID_number[15];
	time Sign_in_time;
	time Sign_out_time;
}node;


node sample[1000];

int main()
{
	int m = 0;
	int earlest_num = 0, latest_num = 0;
	int earlest_time = 0, latest_time = 0;

	while(scanf("%d", &m) != EOF)
	{
		for (int i = 0; i < m; i++)
		{
			scanf("%s", sample[i].ID_number);
			scanf("%d:%d:%d", &sample[i].Sign_in_time.hour, &sample[i].Sign_in_time.minute, &sample[i].Sign_in_time.second);
			scanf("%d:%d:%d", &sample[i].Sign_out_time.hour, &sample[i].Sign_out_time.minute, &sample[i].Sign_out_time.second);
		}
		earlest_num = 0, latest_num = 0;
		earlest_time = sample[0].Sign_in_time.hour * 3600 + sample[0].Sign_in_time.minute * 60 + sample[0].Sign_in_time.second; 
		latest_time = sample[0].Sign_out_time.hour * 3600 + sample[0].Sign_out_time.minute * 60 + sample[0].Sign_out_time.second; 

		for (int i = 1; i < m; i++)
		{
			if (sample[i].Sign_in_time.hour * 3600 + sample[i].Sign_in_time.minute * 60 + sample[i].Sign_in_time.second < earlest_time)
			{
				earlest_num = i;
				earlest_time = sample[i].Sign_in_time.hour * 3600 + sample[i].Sign_in_time.minute * 60 + sample[i].Sign_in_time.second; 
			}

			if (sample[i].Sign_out_time.hour * 3600 + sample[i].Sign_out_time.minute * 60 + sample[i].Sign_out_time.second > latest_time)
			{
				latest_num = i;
				latest_time = sample[i].Sign_out_time.hour * 3600 + sample[i].Sign_out_time.minute * 60 + sample[i].Sign_out_time.second; 
			}
		}

		printf("%s %s\n", sample[earlest_num].ID_number, sample[latest_num].ID_number);
	}
	return 0;
}