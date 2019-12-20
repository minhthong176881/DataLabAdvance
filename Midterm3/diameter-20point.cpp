#include <iostream>
#include <vector>
using namespace std;
 
#define MAX 1000002
#define INF 1000000009
 
vector<int> A[MAX];
vector<int> c[MAX];
int n, m;
int k;
int arr[MAX];
 
int d[MAX]; // key
int node[MAX]; // gia tri node
int idx[MAX]; // index cua node tuong ung trong array
int sH; // size of array
bool fix[MAX];
 
void swap(int i, int j) {
    int tmp = node[i];
    node[i] = node[j];
    node[j] = tmp;
    idx[node[i]] = i;
    idx[node[j]] = j;
}
 
void upHeap(int i) {
    if(i == 0) return;
    while(i > 0) {
        int pi = (i - 1) / 2;
        if(d[node[i]] < d[node[pi]]) {
            swap(i, pi);
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
 
int distance(int s, int t) {
    sH = 0;
    for(int v=1; v <= n; ++v) {
        fix[v] = false;
        idx[v] = -1;
    }
    d[s] = 0;
    fix[s] = true;
    for(int i=0; i < A[s].size(); ++i) {
        int v = A[s][i];
        insert(v,c[s][i]);
    }
    while(sH > 0) {
        int u = deleteMin();
        fix[u] = true;
        for(int i=0; i < A[u].size(); ++i) {
            int v = A[u][i];
            if(fix[v]) continue;
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
    if(!fix[t]) rs = -1;
    return rs;
}
 
int solve(){
    int ans = 0;
    for(int i = 2; i <= k; i++){
        for(int j = 1; j < i; j++){
            if(ans < distance(arr[j], arr[i])) ans = distance(arr[j], arr[i]);
        }
    }
    return ans;
}
 
void input() {
    cin >> n >> m;
    for(int k = 1; k <= m; k++) { // Take Edges
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(v);
        c[u].push_back(w);
        A[v].push_back(u);
        c[v].push_back(w);
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> arr[i];
    }
}
 
// Driver code
int main() {
    input();
    cout << solve() << endl;
    solve();
}

/*
6 10
1 2 2
1 5 6
1 6 1
2 3 8
2 6 4
3 4 7
3 6 2
4 5 3
4 6 5
5 6 4
3
1 3 4
*/