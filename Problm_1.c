/*
Question_1: Currency
In Indian Currency notes and coins are available from Rs. 1, Rs. 2, Rs. 5, Rs. 10, Rs. 20, Rs. 50, Rs. 100, Rs. 200, Rs. 500, and Rs. 2000. A person saves a valid amount not exceeding a sum of Rs. 25000 with least number of notes or coins. Write a program to determine the number of notes or coins when the total saving amount is given. IT will display “Error” for any invalid cause of the program.

Input Format
An Integer representing the valid amount.

Output Format
10 space separated integers representing the frequency of the denomination respectively for Rs. 2000, Rs. 500, Rs. 200, Rs. 100, Rs. 50, Rs. 20, Rs. 10, Rs. 5, Rs. 2, Rs. 1.
*/

#include <stdio.h>
#include <stdlib.h>

void check_error(int s)
{
    if (s < 0 || s > 25000)
    {
        printf("Error");
    }
}

int saves_currency(int a[], int n)
{
    int b[10];
    for (int i = 0; i <= 9; i++)
    {
        if (n >= a[i])
        {
            b[i] = (n / a[i]);
            n = (n % a[i]);
        }
        else{
            b[i]=0;
        }
    };
     for (int j = 0; j <=9; j++)
     {
        printf("%d\t", b[j]);
    }
}

int main(int argc, char const *argv[])
{
    int i, saves, currency_arr[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    printf("\nEnter your saves: ");
    scanf("%d", &saves);
    check_error(saves);
    saves_currency(currency_arr, saves);
    return 0;
}
