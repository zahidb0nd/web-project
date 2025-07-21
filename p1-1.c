#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

int linsearch(int, int[], int);

void main()
{
    int n, i, a[20], k, pos;
    clock_t begin, end;
    double t;

    clrscr();

    printf("\nEnter the number of elements\n");
    scanf("%d", &n);

    printf("\nEnter the elements of an array\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the element to be searched\n");
    scanf("%d", &k);

    begin = clock();
    pos = linsearch(n, a, k);
    end = clock();

    if(pos == -1)
        printf("\n\nUnsuccessful search");
    else
        printf("\nElement %d is found at position %d", k, pos + 1);

    t = (double)(end - begin) / CLK_TCK;
    printf("\nTime taken is %lf CPU cycles\n", t);

    getch();
}

int linsearch(int n, int a[], int k)
{
    delay(1000); // simulate delay
    if(n < 0)
        return -1;
    if(k == a[n - 1])
        return (n - 1);
    else
        return linsearch(n - 1, a, k);
}
