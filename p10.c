#include <stdio.h>
#include <conio.h>

int main()
{
    int cost[10][10], visited[10] = {0};
    int i, j, n, no_e = 1, min, a, b, min_cost = 0;

    clrscr();

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost in form of adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            // If cost is 0, treat it as infinite
            if(cost[i][j] == 0)
                cost[i][j] = 1000;
        }
    }

    // Start from first node
    visited[1] = 1;

    while(no_e < n)
    {
        min = 1000;

        // Find minimum cost edge from visited to unvisited
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        // Add the selected edge to MST
        if(visited[b] == 0)
        {
            printf("\n%d to %d cost = %d", a, b, min);
            min_cost += min;
            no_e++;
        }

        visited[b] = 1;
        cost[a][b] = cost[b][a] = 1000;  // Mark edge as used
    }

    printf("\nMinimum weight is %d", min_cost);

    getch();
    return 0;
}
