#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int n; /* number of points*/
int c[max][max];
int cmin; /* minimum distance*/

/*solution representation*/
int x[max];
int appear[max]; 
int f; /* accumulate distance of the route under construction*/
int f_best; /*shortest distance found so far*/
int x_best[max]; /*record the best route*/

void input(){
	int i, j;
	scanf("%d", &n);
	cmin = 1000000;
	for(i = 0; i <= n; i++){
		for(j = 0; j <= n; j++){
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
	if(f + c[x[n]][0] < f_best){
		f_best = f + c[x[n]][0];
		for(i = 0; i <= n; i++) x_best[i] = x[i];
	}
}

void TRY(int k){
	int v;
	for(v = 1; v <= n; v++){
		if(check(v, k)){
			x[k] = v;
			f += c[x[k-1]][x[k]];
			appear[v] = 1;
			if(k == n) solution();
			else{
				if(f + (n + 1 - k) * cmin < f_best)
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
	f_best = 1000000;
	for(i = 1; i <= n; i++){
		appear[i] = 0;
	}
	x[0] = 0; /* starting point*/
	TRY(1);
	printf("%d", f_best);
}

int main(){
	input();
	solve();
	return 0;
}
