#include <bits/stdc++.h>
#define oo 999999999
#define MOD 1000000007
#define MAX 100030

using namespace std;
typedef unsigned long long ull;

int n;
vector<int> adj[MAX][2];
int d[MAX];
int dmax, vmax;
int result;


void output () {
	printf("%d\n", result);
}

void longestBFS (int vertice) {
	deque<int> q;
	for (int i = 1; i <= n; ++i) {
		d[i] = -1;
	}
	q.push_back(vertice);
	d[vertice] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (int i = 0; i < adj[u][0].size(); ++i) {
			int v = adj[u][0][i];
			int w = adj[u][1][i];
			if (d[v] < 0) {
				q.push_back(v);
				d[v] = d[u] + w;
				if (d[v] > dmax) {
					dmax = d[v];
					vmax = v;
				}
			}
		}
	}
}

void solve () {
	longestBFS(1);				// Phase 1: longest path from 1 to x
	longestBFS(vmax);			// Phase 2: longest path form x to y
	result = dmax;				// Longest path is distance from x to y
}

void input () {
	scanf("%d", &n);
	int u, v, w;
	for (int i = 0; i < n-1; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		adj[u][0].push_back(v);
		adj[u][1].push_back(w);
		adj[v][0].push_back(u);
		adj[v][1].push_back(w);
	}
}

int main () {
	// freopen("inp", "r", stdin);
	// freopen("out", "w", stdout);
	input();
	solve();
	output();
	return 0;
}