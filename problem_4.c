/*
Problem Statement: Magical Number
Let a N digit number is given, P and Q are two numbers, which hold the multiplication of all even and odd position digits respectively. If P is greater or equal to Q then the number is "Dominant", otherwise "Magical". The digit will not be considered, if it is zero and N must not be grater than ten. Write a program to find Dominant or magical number among K given numbers. For any invalid reason it will display "Error". The negative numbers are invalid.
Input Format
Total numbers input and the individual number separated by space.
Output Format
Space separated conclusion of each number whether they are "Magical", "Dominant" or "Error". 
Constraints
The numbers given never be negative. Zero in the digits never be considered in multiplication
Time Limit2s.Each test case should pass in 2s.Sample Input4 65 56 0 12345Sample OutputMagical Dominant Error Magical
*/

#include<stdio.h>
#include<stdlib.h>


void check_error(int n,int arr[])
{
	int i,s,k=1;
	for(i=0;i<n;i++)
	{
		s=arr[i];
		while(s/10 != 0)
		{
			s=s/10;
			k=k+1;
		}
		if(k>10)
		{
			printf("Error");
			exit(0);
		}
	}
}

void check(int n,int arr[])
{
	int i,s,j,l,d,p=1,q=1,k=0;
	int a[10];
	for(i=0;i<n;i++)
	{
		if(arr[i]<=0)
			printf("Error ");
		else
		{
		s=arr[i];
		j=0;
		while(s/10 != 0)
		{
			a[j]=s%10;
			s=s/10;
			k=k+1;
			j=j+1;
		}
		a[j]=s;
		d=1;
		for(l=j;l>=0;l--)
		{
			if(d%2==0)
				p=p*a[l];
			else
				q=q*a[l];
				d=d+1;	
		}
		if(p<=q)
			printf("Magical ");
		else
			printf("Dominant ");
		}
	}
}

int main()
{
	int n,i;
	int arr[n];
	printf("How many numbers you want to insert:");
	scanf("%d",&n);
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	check_error(n,arr);
	check(n,arr);
}