/*
Buying Shirts

✨ Problem Statement

Mr. Kumar wants to buy some shirts and to do that he has a fixed budget B. The shop has N number of shirts having prices p0, p1, p2, ..., p(n-1). Help Mr. Kumar to predict the maximum number of shirts he can buy with his budget.

For example, if Mr. Kumar has a budget of 1000 and the shop has 5 shirts with price 200, 360, 420, 910 and 250, then Mr. Kumar can buy 3 shirts at the max

✨ Extra Info
No Extra Information

✨ Input Format
First Line of the input has an integer T which designates the number of test cases.
Each next two lines represent individual test cases.
The first line of the individual test case will have two integers N and B where N 
dictates the number of shirts and B specifies the budget.
The second line of the individual test case will have N integers designating price 
of the corresponding shirts  

Example
---------
INPUT:
4 
5 490 
120 200 40 60 10 
4 300 
400 350 450 380 
4 200 
120 80 90 100 
6 800 
100 80 230 340 90 100 

OUTPUT:
Case #1: 5
Case #2: 0
Case #3: 2
Case #4: 5
---------------------------

*/

#include <stdio.h>
#include <stdlib.h>

int cal(int b, int arr[], int n)
{
    int c = 0, add = 0;
    for (size_t i = 0; i < n; i++)
    {
        add += arr[i];
        if (add <= b)
        {
            c++;
        }
    }
    // printf("\n%d\t%d", b, add);
    return c;
}

int My_Fun(int n, int b, int num[])
{
    int a;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (num[i] > num[j])
            {
                a = num[i];
                num[i] = num[j];
                num[j] = a;
            }
        }
        // printf("%d\t", num[i]);
    }
    int z;
    z = cal(b, num, n);
    return z;
}

int main(int argc, char const *argv[])
{
    int t, n, budget, arr[100], brr[10];
    printf("INPUT: \n");
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        scanf("%d", &budget);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }

        brr[i] = My_Fun(n, budget, arr);
        // printf("\nCase #%d: %d\n", i + 1,My_Fun(n, budget, arr));
    }
    printf("\nOUTPUT: ");
    for (int j = 0; j < t; j++)
    {
        printf("\nCase #%d: %d", j + 1, brr[j]);
    }
    return 0;
}
