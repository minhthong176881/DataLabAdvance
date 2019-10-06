#include <stdio.h>
#define MAX 100
//data structure for input

int n; //number of points
int c[MAX][MAX];
int cmin; //minimum distance
int k;
//solution representation

int x[MAX] = {0};
int appear[MAX] = {0}; //appear[v]=1 indicates that point v has been visited
int count = 0;
int f = 0; //accumulate distance of the route

int f_best; //the best route

void input()
{
    scanf("%d", &n);
    scanf("%d", &k);
    cmin = 1000000;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            scanf("%d", &c[i][j]);
            if (i != j && cmin > c[i][j])
                cmin = c[i][j];
        }
    }
}

int check(int v)
{
    if (v <= n)
    {
        if (appear[v] == 1 || count == k)
            return 0;
        else
        {
            return 1;
        }
    }
    else
    {
        if (appear[v] == 1 || appear[v - n] == 0)
            return 0;
        else
        {
            return 1;
        }
    }
}

void solution()
{
    if (f + c[x[2 * n]][0] < f_best)
    {
        f_best = f + c[x[2 * n]][0];
    }
}

void TRY(int k)
{
    for (int v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            x[k] = v;
            f += c[x[k - 1]][x[k]];
            appear[v] = 1;
            if (v <= n)
            {
                count++;
            }
            else
            {
                count--;
            }
            if (k == 2 * n)
                solution();
            else
            {
                if (f + (2 * n + 1 - k) * cmin < f_best)
                    TRY(k + 1);
            }
            appear[v] = 0;
            f -= c[x[k - 1]][x[k]];
            if (v <= n)
            {
                count--;
            }
            else
            {
                count++;
            }
        }
    }
}

void solve()
{
    f = 0;
    f_best = 1000000007;
    x[0] = 0; //starting point
    TRY(1);
    printf("%d", f_best);
}

int main()
{
    input();
    solve();
    return 0;
}