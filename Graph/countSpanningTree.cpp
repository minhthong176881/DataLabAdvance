#include<iostream>
#include<set>
#include<vector>
#define MAX_N 101
#define MAX_M 1000

using namespace std;

int N, M;
int b[MAX_M];
int e[MAX_M];
int X[MAX_N]; //model solution set of indicate of edges of spanning tree
int ans;

//data structures for disjoint set
int r[MAX_N];
int p[MAX_N];
long long rs;
void link(int x, int y){
    if(r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1;
    }
}

void makeSet(int x){
    p[x] = x;
    r[x] = 0;
}

int findSet(int x){
    if(x != p[x])
        p[x] = findSet(p[x]);
    return p[x];
}

void input(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> b[i] >> e[j];
    }
}

void inputFile(char* f){
    fstream
}

int checkNoCycle(int val, int k){
    //check if set edge ()
    //induce the cycle
    for(int i = 1; i <= N; i++) makeSet(i);
    for(int j = 1; j < k; j++){
        int u = b [X[j]];
        int v = e[X[j]];
        int ru = findSet(u);
        int rv = findSet(v);
        if(ru == rv) return 0 // node u and v belong to the same set -> creating a cycle
        link(ru, rv); //otherwise, link two sets together
    }
    if(findSet(b[val]) == findSet(e[val])) return 0;
    return 1;
}

void solution(){
    ans++;
    cout << ans;
    for(int i = 1; i <= N; i++) cout << "(" << b[X[i]] << ";" << e[X[i]] << ")"; cout << endl;
}

void TRY(int k){
    for(int v = X[k - 1] + 1; v <= N; v++){
        if(checkNoCycle(v, k)){
            X[k] = v;
            if(k == N - 1){
                solution();
            }
        }
    }
}

void solve(){
    ans = 0; 
    X[0] = 0;
    TRY(1);
    cout << ans;
}

int main(){
    char * fi = "";
    inputFile(fi);
    solve();
}