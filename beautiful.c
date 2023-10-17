#include<stdio.h>
/**
 * main - adds two numbers
 * Return: 0 (Success)
 */
int main(void)
{
int a, b, sum;
printf("Enter a: ");
scanf("%d", &a);
printf("Enter b: ");
scanf("%d", &b);
sum = a + b;
printf("Sum of and b is: %d", sum);
return (0);
}
