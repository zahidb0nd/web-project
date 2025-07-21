#include <stdio.h>
#include <conio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v)
{
    q[++r] = v;
    visited[v] = 1;

    while(f <= r)
    {
        for(i = 1; i <= n; i++)
        {
            if(a[v][i] && !visited[i])
            {
                visited[i] = 1;
                q[++r] = i;
            }
        }
        v = q[++f];
    }
}

void main()
{
    int v;
    clrscr();

    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("\n Enter graph data in matrix form:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n Enter the starting vertex: ");
    scanf("%d", &v);

    bfs(v);

    printf("\n The nodes which are reachable are:\n");
    for(i = 0; i <= r; i++)
    {
        printf("%d\t", q[i]);
    }

    getch();
}
