#include <iostream>
#define MAXN 107
#define MAXM 507
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;

int n, m;
int a[MAXN];
long long s[MAXN][MAXM];
long long sum[MAXN] = {0};
void input(){
    cin >> n >> m;
    for (int i = 1; i <=n; i++)
    {
        cin >> a[i];
    }
}

void solve(){
    int k, i, j;
    float ub;
    for(k = 1; k <= m; k++){
        if(k % a[1] == 0) s[1][k] = 1;
        else s[1][k] = 0;
    }

    for(i = 2; i <= n; i++){
        for(j = 1; j <= i - 1; j++){
            sum[i] += a[j]; 
        }
        for(k = 1; k <= m; k++){
            ub = (k - sum[i])/a[i];
            s[i][k] = 0;
            for(int v = 1; v <= ub; v++){
                s[i][k] = (s[i][k] % MOD + s[i-1][k-v*a[i]] % MOD) % MOD;
            }
        }
    }
}

void output(){
    cout << s[n][m];
}

int main(){
    input();
    solve();
    output();
}