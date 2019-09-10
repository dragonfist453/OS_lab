#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
	int fact=1,i;
	for(i=1;i<=n;i++)
		fact = fact * i;
	return fact;
}

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int r = atoi(argv[2]);
	if(n<r)
		printf("Splitting %d into %d places is not possible so bye!\n\n",n,r);
	else
	{
		int ncr =  factorial(n)/(factorial(r)*factorial(n-r));
		printf("%d\n C = %d\n  %d\n\n",n,ncr,r);
	}
	return 0;
}
