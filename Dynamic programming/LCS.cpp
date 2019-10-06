#include <iostream>
#define MAX 1000001
using namespace std;

int n, m;
int X[MAX];
int Y[MAX];
int S[MAX][MAX];
int ans = -1;                                                                                                                                                                                                                                                                    

int solve(int X[], int Y[])
{
    int i, j;
    for(i = 1; i <= n; i++){
        if(X[i] == Y[1]) S[i][1] = 1;
        else S[i][1] = 0;
    }
    for(j = 1; j <= m; j++){
        if(X[1] == Y[j]) S[1][j] = 1;
        else S[1][j] = 0;
    }
    for(i = 2; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(X[i] == Y[j]) S[i][j] = S[i - 1][j - 1] + 1;
            else{
                if(S[i - 1][j] > S[i][j - 1]) S[i][j] = S[i - 1][j];
                else S[i][j] = S[i][j - 1];
            }
            if(ans < S[i][j]) ans = S[i][j];
        }
    }
    return ans;
}

int main(){
    cin >> n;
    cin >> m;
    for(int i = 0; i < n; i++){
        cin >> X[i];
    }
    for(int j = 0; j < m; j++){
        cin >> Y[j];
    }
    cout << solve(X, Y) << endl;
}