/*
ArrayJumping

✨ Problem Statement
You are given an array of integers where each element represents the max number of jump that can be made forward from that element. Your task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you can not jump at all which essentially means that you cannot move through that element.

✨ Extra Info

✨ Input Format
First line of the input will have an integer N representing the length of the array
Second line will have N number of space separated integers representing the maximum number of jumps allowed. 

✨ Output Format
Integer representing number of minimum jumps required to cross through the array from the very first element, or -1 if crossing through the array is not possible

✨ Constraints
Length of the array would be lesser than 1000
Each Array element would be lesser than 100
*/

#include <stdio.h>
#include <stdlib.h>

int jumping(int l, int n, int arr1[])
{
    int c = -1;
    if (n == l)
    {
        return 0;
    }
    if (arr1[l] == 0)
    {
        return -1;
    }
    for (int i = l + 1; i <= n && i <= l + arr1[l]; i++)
    {
        int jumps = jumping(i, n,arr1);
        if (jumps != -1 && jumps + 1 < c)
            c = jumps + 1;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("INPUT:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("OUTPUT: %d", jumping(0, n, arr));

    return 0;
}
