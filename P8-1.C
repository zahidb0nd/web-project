#include <stdio.h>
#include <conio.h>

void main()
{
    float a[100], sum = 0, x;
    int n, i;

    clrscr();

    printf("\nEnter the degree of the polynomial: ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of the polynomial (from highest to constant term):\n");
    for(i = n; i >= 0; i--)
    {
	printf("Coefficient of X^%d: ", i);
	scanf("%f", &a[i]);
    }

    printf("\nEnter the value of X: ");
    scanf("%f", &x);

    // Horner's Rule evaluation
    for(i = n; i > 0; i--)
    {
        sum = (sum + a[i]) * x;
    }
    sum = sum + a[0];

    printf("\nValue of the polynomial is = %.2f", sum);

    getch();
}
