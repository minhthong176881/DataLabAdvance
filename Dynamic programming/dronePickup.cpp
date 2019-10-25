#include <bits/stdc++.h>
#define oo 999999999
#define MOD 1000000007
#define MAX 4000
 
using namespace std;
typedef unsigned long long ull;
 
int c[MAX];
int a[MAX];
int dp[MAX][200];
int n, k;
int result;
 
void output () {
    printf("%d\n", result < 0 ? -1 : result);
}
 
void solve () {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k+1; ++j)
            dp[i][j] = -oo;
    }
    dp[1][1] = c[1];
   
    result = -1;
    for (int j = 1; j <= k; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int s = i+1; s <= i+a[i]; ++s) {
                dp[s][j+1] = max(dp[i][j] + c[s], dp[s][j+1]);
            }
        }
        if (dp[n][j+1] > result) {
            result = dp[n][j+1];
        }
    }
   
}
 
void input () {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
}
 
int main () {
    input();
    solve();
    output();
    return 0;
}