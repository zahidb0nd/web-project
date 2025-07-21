#include <stdio.h>
#include <conio.h>

// Function to compute Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    // Recursive formula
    return binomialCoeff(n - 1, k - 1) + binomialCoeff(n - 1, k);
}

void main()
{
    int n, k;

    clrscr();

    printf("Enter the value of n and k:\n");
    scanf("%d %d", &n, &k);

    printf("Value of C(%d, %d) is %d", n, k, binomialCoeff(n, k));

    getch();
}
