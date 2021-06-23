/*
5. If the birthday and current date is given for a man...then calculate the total number of days of his life at current point of time. The date of birth and the current date is given. The total weeks of his life will decide whether the wil get Grant or not. If the sum all the prime factors is greater than other he will get it.
*/

#include <stdio.h>
#include <stdlib.h>

void prime(int w)
{
    int Number, i = 1, j, Count, k = 1, l = 1;
    while (i <= w)
    {
        Count = 0;
        if (w % i == 0)
        {
            j = 1;
            while (j <= i)
            {
                if (i % j == 0)
                {
                    Count++;
                }
                j++;
            }
            if (Count == 2)
            {
                k = k * i;
            }
            else
            {
                l = l * i;
            }
        }
        i++;
    }
    printf("\nmult of all prime fact:%d ", k);
    printf("\nmult of all non prime fact:%d ", l);

    if (k > l)
    {
        printf("\nNOT GRANT");
    }
    else
    {
        printf("\nGRANT");
    }
}

int check_error(int C_a[], int B_a[])
{
    if (C_a[0] == 0 || B_a[0] == 0 || C_a[1] == 0 || B_a[1] == 0 || C_a[2] == 0 || B_a[2] == 0 || C_a[0] >= 32 || B_a[0] >= 32 || C_a[1] >= 13 || B_a[1] >= 13)
    {
        printf("\nError");
        exit(0);
    }
}

int findAge(int C_a[], int B_a[])
{
    int month[] = {31, 28, 31, 30, 31, 30, 31,
                   31, 30, 31, 30, 31};

    if (B_a[0] > C_a[0])
    {
        C_a[0] = C_a[0] + month[B_a[1] - 1];
        C_a[1] = C_a[1] - 1;
    }

    if (B_a[1] > C_a[1])
    {
        C_a[2] = C_a[2] - 1;
        C_a[1] = C_a[1] + 12;
    }

    int age_arr[3];

    age_arr[0] = C_a[0] - B_a[0];
    age_arr[1] = C_a[1] - B_a[1];
    age_arr[2] = C_a[2] - B_a[2];

    printf("Present Age\nYears: %d Months: %d Days: %d\n", age_arr[2], age_arr[1], age_arr[0]);
    int day;
    day = (age_arr[2] * 365.25) + (age_arr[1] * 30.4375) + (age_arr[0]);
    printf("\nNumber of weeks: %d\n", day / 7);
    return day / 7;
}

int main()
{
    int C_arr[3], B_arr[3], week;
    printf("\nEnter current date(dd mm yyyy): ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &C_arr[i]);
    };
    printf(" \nEnter birthday date(dd mm yyyy): ");
    for (int j = 0; j < 3; j++)
    {
        scanf("%d", &B_arr[j]);
    };
    check_error(C_arr, B_arr);

    week = findAge(C_arr, B_arr);
    prime(week);
}
