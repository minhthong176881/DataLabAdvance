#include<iostream>
using namespace std;
#define MAX 1000001
int n;
int a[MAX];
int s[MAX];
int ans;

void maxSubseq(int *a){
    s[1] = a[1];
    ans = s[1];
    for (int i = 2; i <= n; i++)
    {
        if(s[i - 1] > 0)
            s[i] = s[i - 1] + a[i];
        else s[i] = a[i];
        if(ans < s[i]) ans = s[i];
    }
    cout << ans << endl;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    maxSubseq(a);
    return 0;
}