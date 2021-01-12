#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[50][20];
int p=-1;

void push()
{
    if (p==49)
        printf("Stack Overflow \n");
    else{
        p+=1;
        scanf("%s",stack[p]);
    }
}

void pop(){
    if (p==-1)
        printf("Stack Underflow \n");
    else {
        printf("URL removed: %s \n", stack[p]);
        p-=1;
        printf("Currently on: %s \n", stack[p]);
    }
}

void display(){
    printf("Elements \n");
    for (int i=0;i<=p;i++)
        printf("%s\n",stack[i]);
        printf("\n");
}
int main(){
    int n,x;
    for (int i=0;i==0;){
    printf("Enter choice:\n1.New URL \n2.Back Button \n3.Display \n4.Stop\n");
    scanf("%d",&n);
    switch (n){
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Wrong Choice\n");
        break;
    }
    }
    return 0;
}