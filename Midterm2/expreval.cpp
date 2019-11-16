#include<iostream>
#define MOD 1000000007
using namespace std;

int n;
int a[300000];
int d[300000];
int sum[300000];
int ans = 0;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        // if(a[i] < 0) a[i] = abs(a[i]) * -1;
    }
    for(int i = 2; i <= n; i++) cin >> d[i];
}

int mod(int b){
	if(b >= 0) return b % MOD;
	if(abs(b) <= MOD) return MOD + b;
	b = abs(b);
	int k = b / MOD;
	b = b - k * MOD;
	return MOD - b;
}

int Expreval(){
    sum[1] = a[1];
    for(int i = 2; i <= n; i++){
        if(d[i] == 2){
        	a[i] = a[i - 1] * a[i];
            a[i - 1] = 0;
            if(d[i - 1] != NULL){
                d[i] = d[i - 1];
            }
        }
    }
    for(int i = 2; i <= n; i++){   
        if(d[i] == 0){
            sum[i] = mod(sum[i - 1] - a[i]);
        }
        else if(d[i] == 1){
            sum[i] = mod(sum[i - 1] + a[i]);
        }
    }
    ans = mod(sum[n]);
    return mod(ans);
}

int main(){
    input();
    cout << Expreval() << endl;
    return 0;
}