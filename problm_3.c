/*
Problem Statement: Swan & Eggs
A farmer has N number of swans of different ages. A swan can give approximately four eggs in a week when it will be 13 months of age. The farmer usually exports eggs monthly. If the valid ages of the swans are given in weeks at the beginning of a month, then write a program to compute the total number of eggs in the end of the month. A month is considered as 4 weeks.
Input Format
The number of swan and their weights in integer and separated by space.
 
Output Format
The total number of eggs at the end of the month.
Constraints
The age of any swan must be valid one. 
Time Limit2s.Each test case should pass in 2s.Sample Input4 51 52 53 54 Sample Output60
*/

#include <stdio.h>
#include <stdlib.h>

void count_egg(int ca[])
{
  int e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0;
  for (int i = 1; i <= ca[0]; i++)
  {
    if (ca[i] >= 52)
    {
      e1 += 16;
    }
    else if (ca[i] == 51)
    {
      e2 += 12;
    }
    else if (ca[i] == 50)
    {
      e3 += 8;
    }
    else if (ca[i] == 49)
    {
      e4 += 4;
    }
  };
  e5 = e1 + e2 + e3 + e4;
  printf("\nOUTPUT :%d", e5);
}

void check_error(int a[])
{
  if (a[0] < 0)
  {
    printf("\n Error");
    exit(0);
  }
  for (int i = 1; i < a[0]; i++)
  {
    if (a[i] == 0)
    {
      printf("\n Error");
      exit(0);
    }
  };
}
int main()
{
  printf("INPUT :");
  int i = 0;
  int arr[10000];
  char temp;
  do
  {
    scanf("%d%c", &arr[i], &temp);
    i++;
  } while (temp != '\n');
  check_error(arr);
  count_egg(arr);
  return 0;
}
