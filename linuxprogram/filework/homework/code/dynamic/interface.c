#include "head.h"
void menu()
{
	int choose;
	char filename[64];
	int size=64;
	char name[size];
	int i=0;
	while(1){
		puts("********************************************");
		puts("*           1. Create a new file           *");
		puts("*           2. Write a document            *");
		puts("*           3. Read a document             *");
		puts("*           4. Modify file permissions     *");
		puts("*           5. View the file permissions   *");
		puts("*           0. exit                        *");
		puts("********************************************");
		puts("");
		printf("please input your choose:");
		scanf("%d",&choose);
		getchar();
		switch(choose)
		{
			case 1:
				puts("Please enter the file name:");
				scanf("%s",filename);
				getchar();
				Create_1(filename);
			break;
			case 2:
				puts("Please enter the file name:");
				scanf("%s",filename);
				getchar();
				Write_1(filename);
			break;
			case 3:
				puts("Please enter the file name:");
				scanf("%s",filename);
				getchar();
				Read_1(filename);
			break;
			case 4:
				puts("Please enter the file name:");
				scanf("%s",filename);
				getchar();
				change_per_1(filename);
			break;
			case 5:
				puts("Please enter the file name:");
				scanf("%s",filename);
				getchar();
				view_per_1(filename);
			break;
			case 0:
			exit(0);
			break;	
		}
	}
}

