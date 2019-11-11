#include "head.h"
void Create_1(char *filename)
{
	
	FILE *fd;
	fd=fopen(filename,"r");
	if(fd==NULL)
	{
		fd=fopen(filename,"a");
		if(fd==NULL)
		{
			perror("File created failed!");
		}
		else
		{
			puts("File created successfully!");
		}
	}
	else
	{
		puts("File already exists,creation failed!");
	}
	fclose(fd);
	fd=NULL;
}

void Write_1(char *filename)
{

	FILE *fd;
	fd=fopen(filename,"r+");
	if(fd==NULL){
		perror("FIle open failed!");	
	}
	else
	{	
		char c;
		puts("Please enter what you want to write:");
		while((c=getchar())!='\n')
		{
			fputc(c,fd);
		}
	}
	fclose(fd);
	printf("\n");
	puts("File written successfully!");
}

void Read_1(char *filename)
{
	char buf[1024];
	FILE *fd;
	fd=fopen(filename,"r");
	if(fd==NULL)
	{
		perror("FILE open failed!");		
	}
	else
	{
		puts("The file contents are as follows:");
		 while(!feof(fd))
    	{
              //字符方式读文件
              char cc = fgetc(fd);
              //用独处的字符和EOF进行比较来决定是否读到文件尾部
               if(cc==EOF)
               {
                        break;
               }
               //输出字符
               putchar(cc);
    	}
		printf("\n");
	}
	fclose(fd);
}

void view_per_1(char *filename)
{
	FILE *fp; //文件指针
	int a, b, c, d;

	a = access(filename, F_OK);
	b = access(filename, R_OK);
	c = access(filename, W_OK);
	d = access(filename, X_OK);

	printf("存在？%s,可读？%s,可写？%s,可运行？%s\n",myboolean(a),myboolean(b),myboolean(c),myboolean(d));
}

void change_per_1(char *filename)
{
	char txt[10000]; //文件内容
	FILE *fp; //文件指针
	int choice;//权限选择
	int a, b, c, d;
	int button;
	a = access(filename, F_OK);
	b = access(filename, R_OK);
	c = access(filename, W_OK);
	d = access(filename, X_OK);

	printf("存在？%s,可读？%s,可写？%s,可运行？%s\n",myboolean(a),myboolean(b),myboolean(c),myboolean(d));

	printf("请选择需要修改的权限(单选)：\n");
	printf("1.可读\n");
	printf("2.可写\n");
	printf("3.可执行\n");
	printf("4.可读写执行\n");
	printf("请选择：");
	scanf("%d", &choice);

	switch (choice)
		{
		case 1: chmod(filename, S_IRUSR); break;
		case 2: chmod(filename, S_IWUSR); break;
		case 3: chmod(filename, S_IXUSR); break;
		case 4: chmod(filename, S_IRWXU); break;

		default: printf("输入有误，请重新输入！");

			break;
		}
}

char * myboolean(int p)/*此函数为了方便结果而定义的布尔运算*/
{
	char *f =NULL;
	if(p<0)
	return f="否";
	if(p==0)
	return f="是";
}
