#include<stdio.h>
int findfactorial(int n);
int main()
{
	int n,factorial;
	printf("Enter the number: ");
	scanf("%d",&n);
	factorial = findfactorial(n);
	printf("factorial of a number: %d",factorial);
}
int findfactorial(int n)
{
	int i,f=1;
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	return f;
}
