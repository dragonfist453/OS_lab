#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc>3)
		printf("Yeahhhhh too many strings boiiiiii\n");
	else
	{
		char str[20];
		strcpy(str,argv[1]);
		strcat(str,argv[2]);
		printf("Concatenated string is %s\n",str);
	}
	return 0;
}
