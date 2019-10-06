#include<stdio.h>
#include<stdlib.h>

int n;
int map[100][100];
int mindist;//minimum distance

int x[100];
int best_x[100];
int appeared[100]={0};
int dist;
int bestdist;

void solution(){
    if (dist+map[x[n]][x[n]+n]+map[x[n]+n][0]<bestdist)
    {
        bestdist=dist+map[x[n]][x[n]+n]+map[x[n]+n][0];
       
    }
}

int check(int v, int k){
    if (appeared[v]==1)
    {
        return 0;
    }
    return 1;
}

int TRY(int k){
    for(int v=1;v<=n;v++){
        if(check(v,k)){
                x[k]=v;
                if(k==1){
                	dist+=map[0][x[1]];
                }
                else{
                	dist+=map[x[k-1]][x[k-1]+n]+map[x[k-1]+n][x[k]];
                }
                appeared[v]=1;
                if(k==n)solution();
                else
                {
                    if (dist+(n-k+1)*mindist < bestdist)
                    {
                        TRY(k+1);
                    }
                }
            appeared[v]=0; 
            if(k==1){
                	dist-=map[0][x[1]];
                }
            else{
            	dist=dist-map[x[k-1]][x[k-1]+n]-map[x[k-1]+n][x[k]];
            }
        }
    }
}

void input(){
    scanf("%d",&n);
    mindist=1000000;
    for(int i=0;i<=2*n;i++){
        for(int j=0;j<=2*n;j++){
            scanf("%d",&map[i][j]);
            if(i!=j && mindist>map[i][j])mindist=map[i][j];
        }
    }
}

void solve(){
    dist=0;
    bestdist=1000000007;
    x[0]=0; //starting point
    TRY(1);
    printf("%d",bestdist);
}

int main(){
    input();
    solve();
    return 0;
}