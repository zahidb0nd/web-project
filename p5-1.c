#include <stdio.h>
#include <conio.h>

int power(int a, int n)
{
    int prod = 1, i = 0;
    for(; i < n; i++)
        prod = prod * a;
    return prod;
}

void main()
{
    int a, n, p;

    clrscr();

    printf("Enter the value of a and n:\n");
    scanf("%d %d", &a, &n);

    p = power(a, n);

    printf("a power n (a^n) is %d", p);

    getch();
}
