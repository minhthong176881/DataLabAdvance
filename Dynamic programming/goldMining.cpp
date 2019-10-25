#include<iostream>

using namespace std;

int n, l1, l2;
int a[1000001];
int s[1000001];
int ans;

void input(){
    cin >> n;
    cin >> l1;
    cin >> l2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}

int goldMining(int *a){
    for(int i = 1; i <= n; i++){
        s[i] = a[i];
        for(int j = i - l2; j <= i - l1; j++){
            if(j > 0 && s[i] < s[j] + a[i]) s[i] = s[j] + a[i];
        }
        if(ans < s[i]) ans = s[i];
    }
    return ans;
}

int main(){
    input();
    goldMining(a);
    cout << ans << endl;
    return 0;
}