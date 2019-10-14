#include <iostream>
#define MOD 1000000007
#define MAX 1000030
 
using namespace std;
 
long long n;
long long result;
long long a;
 
void output () {
    printf("%lld", result);
}
 
void solve () {
 
}
 
void input () {
    scanf("%lld", &n);
    result = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        result = (result * a) % MOD;
    }
}
 
int main () {
    input();
    output();
    return 0;
}