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
	printf("Factorial of %d is %d\n",atoi(argv[1]),factorial(atoi(argv[1])));
	return 0;
}
