#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int item;
    struct node *next;
};
typedef struct node *Node;

Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
Node insert_front(Node first,int data)
{
    Node new_node;
    new_node=getNode();
    new_node->item=data;
    new_node->next=NULL;
    if(first==NULL)
    {
        return new_node;
    }
        new_node->next=first;
        first=new_node;
        return first;

}
Node delete_end(Node first)
{
    Node prev,cur;
    if(first==NULL)
    {
        printf("List Is Empty And Cannot be deleted\n");
        return first;
    }
    cur=first;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    prev->next=NULL;
    free(cur);
    return first;
}
void display(Node first)
{
    int count=0;
    Node temp;
    if(first==NULL)
    {
        printf("\nList Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        count++;
        printf("%d\n",temp->item);
    }
    printf("\nNumber of Nodes In The List Are %d\n",count);
}

void search(Node first,int data)
{
    int pos=0;
    Node temp;
    int i;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(temp=first,i=0;temp!=NULL;temp=temp->next,i++)
    {
        if(temp->item==data)
        {
            pos=i+1;
            printf("\nSearch Successfull\n");
            printf("Element Is Found At Position %d\n",pos);
            break;
        }
        else
        {
            pos=0;
        }
    }
    if(pos==0)
    {
       printf("\nSearch Unsuccesfull\n");
    }
}
void sort(Node first)
{
    int t;
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
        return;
    }
    for(Node i=first;i!=NULL;i=i->next)
    {
        for(Node j=i->next;j!=NULL;j=j->next)
        {
            if((i->item)>(j->item))
            {
                t=i->item;
                i->item=j->item;
                j->item=t;
            }
        }
    }
    printf("\nList In Ascending order is\n");
}

int main()
{
    Node first=NULL;
    Node a= NULL;
    Node b=NULL;
    Node ans=NULL;
    int choice,val,pos,n;
    do
    {
        printf("****Actions****\n");
        printf("1:Insert Front\n");
        printf("2:Delete End\n");
        printf("3:Sort the List\n");
        printf("4:Search For an Element\n");
        printf("5:Display the Count and list\n");
        printf("6: Exit\n");
        printf("\nWhich action do you wanna perform?\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Value To Be Inserted\n");
            scanf("%d",&val);
            first=insert_front(first,val);
            break;
        case 2:
            first=delete_end(first);
            break;
        case 3:
            sort(first);
            display(first);
            break;
        case 4:
            printf("Enter the Number To Searched\n");
            scanf("%d",&n);
            search(first,n);
            break;
        case 5:
        printf("\nThe Elements are:\n");
            display(first);
            break;
        }
    }while(choice!=6);
}