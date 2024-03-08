#include<stdio.h>
#include<math.h>
float checkArmstrong(int x,int size)
{
	if(x>0)
	{
		return(pow(x%10,size))+(checkArmstrong(x/10,size));
	}
}
int main()
{
	int x;
	int y,size=0;
	printf("enter integer \n");
	scanf("%d",&x);
	y=x;
	for(y=x;y!=0;++size)
	{
		y /= 10;
	}
	if((int)checkArmstrong(x,size)==x)
	{
		printf("%d is an armstrong number.\n",x);
	}
	else
	{
		printf("%d is not an armstrong number.\n",x);
	}
	return 0;
}
