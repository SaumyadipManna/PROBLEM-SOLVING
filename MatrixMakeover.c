/*
Matrix Makeover

✨ Problem Statement
You are given two n x m matrices A and B. Your task is to make them completely identical. To achieve this goal, you can perform the following actions in a single move.
           1. Choose either one of the matrices A or B.
           2. Choose either one row or one column of the selected matrix.
           3. Increment all the numbers in the selected row or column by 1.
What is the minimal number of moves you are to perform in order to make matrices A and B identical? Or is it just impossible?

✨ Extra Info

✨ Input Format
The first line having two space separated integers gives the value of n and m respectively.

Following n lines each having m space separated integers represents Matrix A

Next n lines each having m space separated integers represents Matrix B
✨ Output Format
Print the minimal number of moves. If impossible print -1.
✨ Constraints
n and m are always lesser than 20
*/

#include <stdio.h>
#include <stdlib.h>

int Makeover(int a[20][20],int b[20][20],int r,int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j]-=b[i][j];
        }   
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j]-a[i][0]-a[0][j]+a[0][0]!=0)
            {
                return -1;
            }   
        }     
    }

    int result=0;
    for (int i = 0; i < r; i++)
    {
        result+=abs(a[i][0]);
    }
    for (int j = 0; j < c; j++)
    {
        result+=abs(a[0][j]-a[0][0]);
    }
    return result;
    
}

int main(int argc, char const *argv[])
{
    int r, c;
    int a[20][20],b[20][20] ,*p = (int *)malloc(r * c * sizeof(int));
    printf("INPUT: ");
    // printf("Enter the number of rows in array:");
    scanf("%d", &r);
    // printf("\nEnter the number of colomns in array:");
    scanf("%d", &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // printf("\nEnter the a[%d][%d] value:", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // printf("\nEnter the a[%d][%d] value:", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    printf("OUTPUT: %d",Makeover(a,b,r,c));
    // printf("\nThe matrix is:");
    // for (int i = 0; i < r; i++)
    // {
    //     printf("\n");
    //     for (int j = 0; j < c; j++)
    //     {
    //         printf(" %d\t", b[i][j]);
    //     }
    // }
    return 0;
}
