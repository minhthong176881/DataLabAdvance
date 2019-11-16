#include<iostream>
#define maxN 1007
#define maxK 407
#define MOD 100000007
using namespace std;

int n, k1, k2;
long long m;
int s[maxN]; // number of solution with days 1, 2, ..., i in which last bit = 0
int s1[maxN]; // number of solution with days 1, 2, ..., i in which last bit = 1

void input(){
    cin >> n >> k1 >> k2;
}

int solve(){
    int i, l;
    for(i = 1; i <= n; i++){
        s[i] = 0;
        s1[i] = 0;
    }
    s[1] = 1; 
    s[0] = 1;
    s1[k1] = 1;
    for(int i = k1 + 1; i <= n; i++){
        s[i] = s1[i - 1];
        s1[i] =0;
        for(l = k1; l <= k2; l++){
            if(i - l >= 0) s1[i] = s1[i] % MOD + s[i - l] % MOD;
        }
    }
    return s[n] % MOD + s1[n] % MOD;
}

int main(){
    input();
    cout << solve() << endl;
    return 0;
}
