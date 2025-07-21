#include <stdio.h>
#include <conio.h>
#include <time.h>

int c = 0;

void toh(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", s, d);
        c++;
        return;
    }

    toh(n - 1, s, d, t);
    printf("Move disk %d from %c to %c\n", n, s, d);
    c++;
    toh(n - 1, t, s, d);
}

void main()
{
    int n;
    clock_t st, et;
    double ts;

    clrscr();

    printf("Enter number of disks: ");
    scanf("%d", &n);

    st = clock();
    toh(n, 'A', 'B', 'C');
    et = clock();

    ts = (double)(et - st) / CLK_TCK;

    printf("\nTotal moves: %d", c);
    printf("\nTime taken is %lf CPU cycles\n", ts);

    getch();
}
