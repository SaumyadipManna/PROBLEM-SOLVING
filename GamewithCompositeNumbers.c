/*
Game with Composite Numbers

✨ Problem Statement
You are given a number N. Print the maximum number of composite numbers that sum up to N. If it is not possible to sum up the number using composite numbers then print -1.

sample input:
   90

   sample output:
   22

   Explanation:
   If we add 21 4's, then we get 84 and the add 6 to it. So 21+1=22.

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   int n;
   printf("INPUT: ");
   scanf("%d", &n);
   printf("OUTPUT: ");
   if (n < 4)
   {
      printf("\n-1");
   }
   else if (n % 4 == 0)
   {
      printf("%d", n / 4);
   }
   else if (n % 4 == 1)
   {
      if (n < 9)
      {
         printf("\n-1");
      }
      else
      {
         printf("%d", (n - 9) / (4) + 1);
      }
   }
   else if (n % 4 == 2)
   {
      printf("%d", (n - 6) / (4) + 1);
   }
   else
   {
      if (n < 15)
      {
         printf("\n-1");
      }
      else
      {
         printf("%d", (n - 15) / (4) + 2);
      }
   }
   return 0;
}
