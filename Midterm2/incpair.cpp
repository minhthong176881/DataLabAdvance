#include<iostream>
#define MAX 1000001
using namespace std;

int n;
int a[MAX];
int count = 0;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j<= n; j++){
            if(a[i] < a[j] && i < j) count++;
        }
    }
    cout << count << endl;
    return 0;
}