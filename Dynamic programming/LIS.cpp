#include<iostream>
#include<climits>
using namespace std;
#define MAX 1000001

int n;
int a[MAX];
int s[MAX];
int ans;

int solve(int a[], int s[]){
    int i;
    s[1] = 1;
    for(i = 2; i <= n; i++){
        s[i] = 1;
        for(int j = 1; j <= i - 1; j++){
            if(a[j] < a[i] && s[i] < s[j] + 1) {
                s[i] = s[j] + 1;
            }
            if(ans < s[i]) ans = s[i];
        }
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, s) << endl;
    return 0;
}
