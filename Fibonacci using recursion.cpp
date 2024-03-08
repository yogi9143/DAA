#include<stdio.h>
int fib(int n);
int main()
{
	int n;
	printf("enter num: ");
	scanf("%d",&n);
	printf("fibonacci series: \n");
	fib(n);
}
int fib(int n)
{
	int a,b,next;
	printf("0 \n1\n");
	a=0;
	b=1;
	next=a+b;
	while(next<=n)
	{
		printf("%d \n", next);
		a=b;
		b=next;
		next=a+b;
	}
}
