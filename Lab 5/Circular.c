#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define que_size 3
int item,front=0,rear=-1,q[que_size],count=0;
void insertrear()
{
	if(count==que_size)
	{
		printf("Queue overflow");
		return;
	}
	rear=(rear+1)%que_size;
	q[rear]=item;
	count++;
}
int deletefront()
{
	if(count==0) return -1;
	item = q[front];
	front=(front+1)%que_size;
	count=count-1;
	return item;
}
void displayq()
{
	int i,f;
	if(count==0)
	{
		printf("Queue is empty");
		return;
	}
	f=front;
	printf("Contents of queue \n");
	for(i=0;i<=count;i++)
	{
		printf("%d\n",q[f]);
		f=(f+1)%que_size;
	}
}
void main()
{
	int choice;
	for(;;)
	{
		printf("\n1.Insert rear 2.Delete front 3.Display 4.Exit \n");
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the item to be inserted :");
			       scanf("%d",&item);
			       insertrear();
			       break;
			case 2:item=deletefront();
				   if(item==-1)
				   printf("Queue is empty\n");
				   else
				   printf("Item deleted is %d \n",item);
				   break;
		    case 3:displayq();
				   break;
		    default:exit(0);		
		}
	}
}