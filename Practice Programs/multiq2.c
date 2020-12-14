#include<stdio.h>
#include<stdlib.h>
#define N 3
int queue[3][N];
int front[3]={0,0,0};
int rear[3]={-1,-1,-1};
int item,pr;
void pqinsert(int);
void pqdelete();
void display();
int  main()
{
    int ch;
    for(;;)
    {
    printf("\nPRIORITY QUEUE\n");
    printf("*****************\n");
    printf("\n\t1:PQ-INSERT\n");
    printf("\n\t2:PQ-DELETE\n");
    printf("\n\t3:PQ-DISPLAY\n");
    printf("\n\t4:EXIT\n");
    printf("\nENTER CHOICE:\n");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nENTER PRIORITY NUMBER\n");
		    scanf("%d",&pr);
		    if(pr>0 && pr<4)
		    pqinsert(pr-1);
		    else
		    printf("ONLY THREE PRIORITY EXITS 1 2 3\n");
		    break;
            case 2:
            pqdelete();
	        break;
            case 3:
            display();
	        break;
            case 4:exit(0);
        }
    }
    return 0;
}
void pqinsert(int pr)
{
    if(rear[pr]==N-1)
    printf("\nQUEUE OVERFLOW\n");
    else
    {
        printf("\nENTER THE ITEM\n");
        scanf("%d",&item);
        rear[pr]++;
        queue[pr][rear[pr]]=item;
    }
}
void pqdelete()
{
    int i;
    for(i=0;i<3;i++)
    {
        if(rear[i]==front[i]-1)
        printf("\nQUEUE EMPTY\n");
        else
        {
            printf("DELETED ITEM IS %d OF QUEUE %d\n",queue[i][front[i]],i+1);
            front[i]++;
        }
    }
}
void display()
{
    int i,j;
    for(i=0;i<3;i++)
    {
        if(rear[i]==front[i]-1)
        printf("\nQUEUE EMPTY %d\n",i+1);
        else
        {
            printf("\nQUEUE %d:",i+1);
            for(j=front[i];j<=rear[i];j++)
            printf("%d\t",queue[i][j]);
        }
    }
}