#include <iostream>
#include <vector>
 
#define MAX 1000002
#define INF 1000000009
 
std::vector<int> A[MAX];
std::vector<int> c[MAX];
int n, m;
int s, t;
 
int d[MAX]; // key
int node[MAX]; // gia tri node
int idx[MAX]; // index cua node tuong ung trong array
int sH; // size of array
bool fixed[MAX];
 
void swap(int i, int j) {
    int tmp = node[i];
    node[i] = node[j];
    node[j] = tmp;
    idx[node[i]]=i;
    idx[node[j]]=j;
}
 
void upHeap(int i) {
    if(i == 0) return;
    while(i > 0) {
        int pi = (i-1)/2;
        if(d[node[i]] < d[node[pi]]) {
            swap(i,pi);
        }
        else {
            break;
        }
        i = pi;
    }
}
 
void downHeap(int i) {
    int L = 2*i + 1;
    int R = 2*i + 2;
    int maxIdx = i;
    if(L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L;
    if(R < sH && d[node[R]] < d[node[maxIdx]]) maxIdx = R;
    if(maxIdx != i) {
        swap(i, maxIdx);
        downHeap(maxIdx);
    }
}
 
void insert(int v, int k) {
    d[v] = k;
    node[sH] = v;
    idx[node[sH]] = sH;
    upHeap(sH);
    sH++;
}
 
bool inHeap(int v) {
    if(idx[v] >= 0) return true;
    else return false;
}
 
void updateKey(int v, int k) {
    if(d[v] > k) {
        d[v] = k;
        upHeap(idx[v]);
    }
    else {
        d[v] = k;
        downHeap(idx[v]);
    }
}
 
int deleteMin() {
    int sel_node = node[0];
    swap(0, sH-1);
    sH--;
    downHeap(0);
    return sel_node;
}
 
void solve() {
    sH = 0;
    for(int v=1; v <= n; ++v) {
        fixed[v] = false;
        idx[v] = -1;
    }
    d[s] = 0;
    fixed[s] = true;
    for(int i=0; i < A[s].size(); ++i) {
        int v = A[s][i];
        insert(v,c[s][i]);
    }
    while(sH > 0) {
        int u = deleteMin();
        fixed[u] = true;
        for(int i=0; i < A[u].size(); ++i) {
            int v = A[u][i];
            if(fixed[v]) continue;
            if(!inHeap(v)) {
                int w = d[u] + c[u][i];
                insert(v,w);
            }
            else {
                if(d[v] > d[u] + c[u][i]) 
                    updateKey(v, d[u] + c[u][i]);
            }
        }
    }
    int rs = d[t];
    if(!fixed[t]) rs = -1;
    std::cout << rs << '\n';
}
 
void input() {
    std::cin >> n >> m;
    for(int k=1; k <= m; k++) { // Take Edges
        int u,v,w;
        std::cin >> u >> v >> w;
        A[u].push_back(v);
        c[u].push_back(w);
    }
    std::cin >> s >> t;
}
 
// Driver code
int main() {
    input();
    solve();
}