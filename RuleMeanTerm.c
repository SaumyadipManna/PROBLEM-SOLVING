/*
Rule Mean Term

✨ Problem Statement
Suppose you are given with an array of 0 and 1 of length n A[n], and config pattern P. You are to form a RMT array of length n R[n] such that Ri = decimal of (A[i-1] A[i] A[i+1]). 

How to compute A[i-1] if i = 0 ? just take A[i-1] = 0 if P = 0 or take A[i-1] = A[n-1] if P = 1. 
Similarly how to compute A[i+1] if i = n-1? just take A[i+1] = 0 if P = 0 or take A[i+1] = A[0] if P = 1

Illustration - 1

Suppose n = 4, P = 1 and A[] = 0 0 1 1

So R[0] = Decimal of (A[0-1] A[0] A[0+1]) = Decimal of (A[3]A[0]A[1]) = Decimal of (100) = 4
R[1] = Decimal of (A[1-1] A[1] A[1+1]) = Decimal of (A[0]A[1]A[2]) = Decimal of (001) = 1
R[2] = Decimal of (A[2-1] A[2] A[2+1]) = Decimal of (A[1]A[2]A[3]) = Decimal of (011) = 3
R[3] = Decimal of (A[3-1] A[3] A[3+1]) = Decimal of (A[2]A[3]A[0]) = Decimal of (110) = 6

Hence R[] = 4 1 3 6
*/

#include <stdio.h>
#include <stdlib.h>

int calculate(int a, int b, int c) //  1 0 1====2**2+2**1+2**0
{
    int ans;
    ans = (4 * a) + (2 * b) + (1 * c);
    return ans;
}

int MeanTerm(int n, int p, int A[])
{
    int z, R[100];
    for (int i = 0; i < n; i++)
    {
        if (i == 0 && p == 0)
        {
            z = calculate(0, A[i], A[i + 1]);
        }
        else if (i == 0 && p == 1)
        {
            z = calculate(A[n - 1], A[i], A[i + 1]);
        }
        else if (i == (n - 1) && p == 0)
        {
            z = calculate(A[i - 1], A[i], 0);
        }
        else if (i == (n - 1) && p == 1)
        {
            z = calculate(A[i - 1], A[i], A[0]);
        }
        else
        {
            z = calculate(A[i - 1], A[i], A[i + 1]);
        }
        R[i] = z;
    }
    for (int j = 0; j < n; j++)
    {
        printf("%d\t", R[j]);
    }
}

void check_error(int n, int p, int A[])
{
    if (n < 0 || n > 100 || p > 1 || p < 0)
    {
        printf("Error");
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] > 1 || A[i] < 0)
        {
            printf("Error");
            exit(0);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, p, A[100];
    printf("INPUT: ");
    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("OUTPUT: ");
    check_error(n, p, A);
    MeanTerm(n, p, A);

    return 0;
}
