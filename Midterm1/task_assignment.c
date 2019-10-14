#include<stdio.h>
#include<stdlib.h>
#define max 32

int m, n, k;
int c[max][max];
int cmin;
int d[max]; //check how many tasks that staff d[j] do
int f;
int f_best;

void TRY(int i){
    for(int j = 1; j <= m; i++){
        if(d[j] < k){
            f += c[j][i];
            d[j]++;
            if(i == n){
                if(f < f_best)
                f_best = f;
            }
            else{
                if(i < n && (f + cmin * (n - i)) < f_best)
                    TRY(i + 1);
            }
            d[j]--;
            f -= c[j][i];
        }
    }
}

int main(){
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    cmin = 1000001;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &c[i][j]);
            if(c[i][j] < cmin)
                cmin = c[i][j];
        }
    }
    f = 0;
    f_best = 1000001;
    TRY(1);
    printf("%d\n", f_best);
    return 0;
}