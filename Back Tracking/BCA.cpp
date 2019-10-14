#include<stdio.h>
#include<stdlib.h>

int n;//number of course
int m;//number of teacher
int dur[50];//dur[x] = durarion of course x
int conflict[50][50];//conflict matrix
int sz[50];//sz[i] = number of teacher for course i
int t[50][10];//x[i][j] = teacher j who teach the course i

int x[50];
int f[10];
int f_best;

void input(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&dur[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&sz[i]);
		for(int j=0;j<sz[i];j++){
			scanf("%d",&t[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)scanf("%d",&conflict[i][j]);
	}
}

int check(int v, int k){
	for(int i=1;i<=k-1;i++){
		if(conflict[i][k] && v==x[i])return 0;
	}
	return 1;
}

void solution(){
	int max=0;
	for(int i=1;i<=m;i++){
		if(max<f[i])max=f[i];
	}
	if(max<f_best)f_best=max;
}

void TRY(int k){//try to find a teacher v for course k
	for(int i=0;i<sz[k];i++){
		int v=t[k][i];
		if(check(v,k)){
			x[k]=v;
			f[v]+=dur[k];//accumulate laod for teacher v
			if(k==n)solution();
			else TRY(k+1);
			f[v]-=dur[k];
		}
	}
}

void solve(){
	f_best=1000000;
	for(int i=1;i<=m;i++) f[i]=0;
	TRY(1);
	if(f_best==1000000)printf("-1");
	else printf("%d\n",f_best);
}

int main(){
	input();
	solve();
	return 0;
}