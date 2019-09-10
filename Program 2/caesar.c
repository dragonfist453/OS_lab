#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i,j;
	for(i=1;i<argc;i++)
	{
		char str[30];
		strcpy(str,argv[i]);
		for(j=0;j<strlen(str);j++)
		{
			if(str[j]=='z')
				str[j] = 'c';
			else if(str[j]=='y')
				str[j] = 'b';
			else if(str[j]=='x')
				str[j] = 'a';
			else
				str[j] += 3;
		}
		printf("Normal string : %s\nCaesar cipher : %s\n",argv[i],str);
	}
	return 0;
}
