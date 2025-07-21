#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>

int binsearch(int, int[], int, int, int);

void main()
{
    double t;
    int n, i, a[20], k, low, high, pos;
    clock_t begin, end;

    clrscr();

    printf("\nEnter the number of elements\n");
    scanf("%d", &n);

    printf("\nEnter the elements of the array in ascending order\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nEnter the element to be searched\n");
    scanf("%d", &k);

    low = 0;
    high = n - 1;

    begin = clock();
    pos = binsearch(n, a, k, low, high);
    end = clock();

    if(pos == -1)
        printf("\n\nUnsuccessful search");
    else
        printf("\nElement %d is found at position %d", k, pos + 1);

    t = (double)(end - begin) / CLK_TCK;
    printf("\nTime taken is %lf CPU cycles\n", t);

    getch();
}

int binsearch(int n, int a[], int k, int low, int high)
{
    int mid;
    delay(1000); // simulate delay

    if(low > high)
        return -1;

    mid = (low + high) / 2;

    if(k == a[mid])
        return mid;
    else if(k < a[mid])
        return binsearch(n, a, k, low, mid - 1);
    else
        return binsearch(n, a, k, mid + 1, high);
}
