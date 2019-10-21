#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <cstring>
using namespace std;

int main()
{
	int fd;
	FILE *file;
	char s[]="hello,world\n";
	if((fd=open("test.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1)
	{
		cout<<"Error open file"<<endl;
		return -1;
	}
	if((file=fopen("test2.txt","w"))==NULL)
	{
		cout<<"Error Open File."<<endl;
		return -1;
	}
	cout<<"File has been Open."<<endl;
	sleep(10);
	if((int)write(fd,s,strlen(s))<(int)strlen(s))
	{
		cout<<"Write Error"<<endl;
		return -1;
	}
	if(fwrite(s,sizeof(char),strlen(s),file)<strlen(s))
	{
		cout<<"Write Error in 2"<<endl;
		return -1;
	}
	cout<<"After write"<<endl;
	sleep(10);
	cout<<"After sleep"<<endl;
	close(fd);
	return 0;
}
