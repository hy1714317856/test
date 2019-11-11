#include <stdio.h>

void main()
{	
	char s[50];
	char c;
	int i=0;
	while((c=getchar())!='\n')
	{
		s[i]=c;
		i++;	
	}
	s[i]='\0';
	puts(s);
}
