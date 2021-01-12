#include<stdio.h>
#include<stdlib.h>
#define que_size 5
int item,front=0,rear=-1,q[que_size],count=0;
void insertrear()
{
	if(count==que_size)
	{
		printf("Can't take more reservations currently. Try again later.\n");
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
	count-=1;
	return item;
}
void displayq()
{
	int i,f;
	if(count==0)
	{
		printf("No reservations found\n");
		return;
	}
	f=front;
	printf("Reservations: \n");
	for(i=0;i<count;i++)
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
		printf("\n1. Reserve Ticket\n2. Cancel last Reservation \n3. display final reservations\n4.exit \n");
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter unique id : ");
			       scanf("%d",&item);
			       insertrear();
			       break;
			case 2:item=deletefront();
				   if(item==-1)
				   printf("No reservations pending for cancellation\n");
				   else
				   printf("Reservation for ID %d cancelled \n",item);
				   break;
		    case 3:displayq();
				   break;
			case 4: exit(0);
		    default:printf("WRONG CHOICE!");
		}
	}
}