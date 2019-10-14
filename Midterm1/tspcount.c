#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int n, m; /* number of points*/
int c[max][max];
int cmin; /* minimum distance*/
int count = 0;

/*solution representation*/
int x[max];
int appear[max]; 
int f; /* accumulate distance of the route under construction*/
int x_best[max]; 

void input(){
	int i, j;
	scanf("%d %d", &n, &m);
	cmin = 1000000;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			scanf("%d", &c[i][j]);
			if(i != j && cmin > c[i][j])
				cmin = c[i][j];
		}
	}
}

int check(int v, int k){
	if(appear[v] == 1) return 0;
	return 1;
}

void solution(){
	int i;
	if(f + c[x[n]][1] <= m){
        count++;
	}
}

void TRY(int k){
	int v;
	for(v = 2; v <= n; v++){
		if(check(v, k)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			appear[v] = 1;
			if(k == n) solution();
			else{
				if(f + (n + 1 - k) * cmin <= m)
					TRY(k + 1);
			}
			appear[v] = 0;
			f -= c[x[k - 1]][x[k]];
		}
	}
}

void solve(){
	int i;
	f = 0;
	for(i = 1; i <= n; i++){
		appear[i] = 0;
	}
	x[1] = 1; /* starting point*/
	TRY(2);
	printf("%d\n", count);
}

int main(){
	input();
	solve();
	return 0;
}
