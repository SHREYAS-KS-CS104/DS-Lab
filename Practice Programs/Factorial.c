#include <stdio.h>
int fact(int n)
{
    if(n==0)
    return 1;
    return n*fact(n-1);
}
int main()
{
    int N;
    printf("Enter the value of N: \n");
    scanf("%d",&N);
    printf("The factorial of %d = %d \n",N,fact(N));
    return 0;
}