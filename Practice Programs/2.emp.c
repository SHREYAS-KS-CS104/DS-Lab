#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define que_size 10
int front=0,rear=-1,count=0;
char nm[20]; int M,ID,T;
char name[que_size][20];
int id[que_size],tim[que_size], mob[que_size];
void insertrear()
{
	if(count==que_size)
	{
		printf("queue overflow\n");
		return;
	}
	rear=(rear+1)%que_size;
	int i=0;
    while(nm[i]!='\0'){
        name[rear][i]=nm[i];i++;
    }
    id[rear]=ID;
    tim[rear]=T;
    mob[rear]=M;
	count++;
}
int deletefront()
{
	if(count==0) return -1;
	ID = id[front];
	front=(front+1)%que_size;
	count-=1;
	return ID;
}
void displayq()
{
	int i,f;
	if(count==0)
	{
		printf("queue is empty\n");
		return;
	}
	f=front;
	printf("Who work more than 8 hours: \n");
	for(i=0;i<count && tim[f]>8;i++)
	{
		printf("%d\t%s\t%d",id[f],name[f],mob[f]);
		f=(f+1)%que_size;
	}
}
void main()
{
	int choice;
	for(;;)
	{
		printf("\n1.Enter employee detail\n2.Delete employee detail \n3. Display who worked more than 8 hours \n4.exit \n");
		printf("Enter the choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter NAME, ID, MOBILE num, Time in hours : ");
			       scanf("%s%d%d%d",nm,&ID,&M,&T);
                   nm[strlen(nm)]='\0';
			       insertrear();
			       break;
			case 2:ID=deletefront();
				   if(ID==-1)
				   printf("queue is empty\n");
				   else
				   printf("ID deleted is %d \n",ID);
				   break;
		    case 3:displayq();
				   break;
			case 4: exit(0);
		    default:printf("WRONG CHOICE!");
		}
	}
}