//programs to implement a double ended queue ADT
#include<stdio.h>
#include<stdlib.h>
void push(void);
void pop(void);
void push1(void);
void display(void);
int top=-1,top1=-1;
#define N 5
int A[N],B[N];
int main()
{
	int ch;
	while(1)
	{
		printf("1.push\n");
		printf("2.exit\n");
		printf("enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:push();
	        break;
	        case 2:exit(1);
	        break;
	        default:printf("invalid selection\n");
		}
	}

}
void push()
{
	if(top==-1)
	{
		printf("list is empty\n");
	}
	int x,i;
	top++;
	for(i=top;i<=N;i++)
	{
		printf("enter the data you want to push\n");
        scanf("%d,&x");

		A[top]=x;
		top++;
	}
	while(top!=-1)
	{
		push1();
		pop();
	}
}
void pop()
{
	top--;
}
void display()
{
	while(top1!=-1)
	printf("%d",B[top1]);
}
void push1()
{
	top1=top1+1;
	B[top1]=A[top];
}

