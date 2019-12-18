#include <bits/stdc++.h>
#define oo 999999999
#define MOD 1000000007
#define MAX 1000000

using namespace std;
typedef unsigned long long ull;

int n, m;
vector<int> adj[MAX];
int d[MAX];			// time
int result;

void output () {
	printf("%d\n", result);
}

void BFS (int vertice) {
	deque<int> q;
	for (int i = 1; i <= n; ++i)
		d[i] = -1;
	q.push_back(vertice);
	d[vertice] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop_front();
		for (auto v : adj[u]) {
			if (d[v] > -1) {
				if (d[u] % 2 == d[v] % 2) {
					result = false;
					return;
				}
			} else {
				q.push_back(v);
				d[v] = d[u] + 1;
			}
		}
	}
	result = 1;
	return;
}

void solve () {
	BFS(1);
	// for (int i = 1; i <= n; ++i) {
	// 	if (d[i] == -1) {
	// 		result = 0;
	// 	}
	// }
}

void input () {
	scanf("%d%d", &n, &m);
	int tmp_u, tmp_v;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &tmp_u, &tmp_v);
		adj[tmp_u].push_back(tmp_v);
		adj[tmp_v].push_back(tmp_u);
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