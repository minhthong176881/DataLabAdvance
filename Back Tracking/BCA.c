#include <stdio.h>
#define MAX_N 50
#define  MAX_M 10

//input data structures

int N; // number of classes
int M; //number of teacher
int sz[MAX_N]; //sz[i] is number of teacher of course i
int t[MAX_N][MAX_M]; //t[c][i]: the ith teacher can teach course c
int h[MAX_N]; //h[c] is the number of hours of class c each week
int A[MAX_N][MAX_N]; // A[i][j] = 1 indicates that course i and j are conflict

//variable

int x[MAX_N]; // x[i] is the teacher assigned to course i
int f[MAX_M]; // f[j] is the load of teacher j
int f_best;

void input(){
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &h[i]);
    }
    for(int i = 1; i <= N; i++){
        scanf("%d", &sz[i]);
        for(int j = 0; j < sz[i]; j++){
            scanf("%d", &t[i][j]);
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            scanf("%d", &A[i][j]);
        }
    }
}

void solution(){
    int max = 0;
    for(int i = 1; i <= M; i++){
        if(max < f[i]) max = f[i];
    }
    if(max < f_best) f_best = max;
    printf("\n");
}

int check(int v, int k){
    for(int i = 1; i <= k - 1; i++){
        if(A[i][k] && v == x[i]){
            return 0;
        }
    }
    return 1;
}

int TRY(int k){ // try to find a teacher (v) for course k
    for(int i = 1; i <= sz[k]; i++){
        int v = t[k][i];
        if(check(v, k)){
            x[k] = v;
            f[v] += h[k]; // accumulate load for teacher v
            if(k == N) solution();
            else TRY(k + 1);
        }
        f[v] -= h[k]; // recover load when backtracking
    }
}

void solve(){
    f_best = 1000000;
    for(int i = 1; i <= M; i++) f[i] = 0;
    TRY(1);
    if(f_best == 1000000) printf("-1");
    else printf("%d", f_best);
}

int main() {
    input();
    solve();
    return 0;
}