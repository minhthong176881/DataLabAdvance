#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a; i<=b; i++)
#define ford(i,a,b) for(int i=a; i>=b; i--)
#define maxn 100
int m, n, k;
int c[maxn][maxn], cmin;
int d[maxn];
int f_best,f;

void TRY(int i)
{
    fore(j, 1, m)
     if(d[j] < k)
     {
         f += c[j][i];
         d[j]++;
         if(i == n)
         {
             if(f < f_best)
                f_best = f;
         }
         else
         {
            if(i < n && (f + cmin*(n - i)) < f_best)
                TRY(i+1);
         }
         d[j]--;
         f -= c[j][i];
     }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    cmin = 1000001;
    fore(i, 1, m)
     fore(j, 1, n)
     {
         scanf("%d", &c[i][j]);
         if(c[i][j] < cmin)
            cmin = c[i][j];
     }

    f = 0;
    f_best = 1000001;
    TRY(1);
    printf("%d\n",f_best);
    return 0;
}
