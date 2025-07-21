#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>

void selsort(int a[], int n);

void main()
{
    int a[20], i, n;
    clock_t st, et;
    double ts;

    clrscr();

    printf("Enter the number of elements (max 20):\n");
    scanf("%d", &n);

    printf("\nThe Random Numbers are:\n");
    for(i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;  // Generate random numbers between 0 and 999
        printf("%d\t", a[i]);
    }

    st = clock();
    delay(50); // Simulated delay for visibility
    selsort(a, n);
    et = clock();

    ts = (double)(et - st) / CLK_TCK;
    printf("\nThe execution time taken is %lf CPU cycles\n", ts);

    getch();
}

void selsort(int a[], int n)
{
    int k, i, j, small, pos, temp;

    for(k = 0; k < n; k++)
    {
        small = a[k];
        pos = k;

        for(i = k + 1; i < n; i++)
        {
            if(small > a[i])
            {
                small = a[i];
                pos = i;
            }
        }

        // Swap a[k] and a[pos]
        temp = a[k];
        a[k] = a[pos];
        a[pos] = temp;
    }

    printf("\nThe sorted array is:\n");
    for(j = 0; j < n; j++)
        printf("%d\t", a[j]);
}
