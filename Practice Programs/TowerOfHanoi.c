#include <stdio.h>
 
void towers(int, char, char, char);
 
int main()
{
    int num;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'S', 'T', 'D');
    return 0;
}
void towers(int num, char S, char T, char D)
{
    if (num == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", S,D);
        return;
    }
    towers(num-1, S,D,T);
    printf("\n Move disk %d from peg %c to peg %c", num,S,D);
    towers(num - 1,T,S,D);
}