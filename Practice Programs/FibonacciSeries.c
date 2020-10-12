#include <stdio.h>
int fib(int n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int i,n;
    printf("ENTER N :\n");
    scanf("%d",&n);
    printf("%d THE FIBONACCI NUMBERS ARE: \n",n);
    for(i=0;i<n;i++)
    {
        printf("fib(%d)=%d\n",i,fib(i));
    }
    return 0;
}