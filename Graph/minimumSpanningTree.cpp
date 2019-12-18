#include<iostream>
#include<set>
#include<vector>
#define MAX 1000001

using namespace std;

//data structure for input graph
int N, M;
int u[MAX];
int v[MAX];
int c[MAX];
int ET[MAX];
int nET;

//data structure for disjoint-set
int r[MAX]; //r[v] is the rank of the set v
int p[MAX]; // p[v] is the parent f v
long long rs;

void link(int x, int y){
    if(r[x] > r[y]) p[y] = x;
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] +1;

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

void swap(int& a, int& b){
    int tmp = a; 
    a = b; 
    b = tmp;
}

void swapEdge(int i, int j){
    swap(c[i], c[j]);
    swap(u[i], u[j]);
    swap(v[i], v[j]);
}

int partition(int L, int R, int index){
    int pivot = c[index];
    swapEdge(index, R);
    int storeIndex = L;
    for(int i = L; i <= R; i++){
        if(c[i] < pivot){
            swapEdge(storeIndex, i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex, R);
    return storeIndex;
}

void quickSort(int L, int R){
    if(L < R){
        int index = (L + R) / 2;
        index = partition(L, R, index);
        if(L < index) quickSort(L, index - 1);
        if(index < R) quickSort(index + 1, R);
    }
}

void quickSort(){
    quickSort(0, M -1);
}

void solve(){
    for(int x = 1; x <= N; x++) makeSet(x);
    quickSort();
    rs = 0;
    int count = 0;
    nET = 0;
    for(int i = 0; i < M; i++){
        int ru = findSet(u[i]);
        int rv = findSet(v[i]);
        if(ru != rv){
            link(ru, rv);
            nET++;
            ET[nET] = 1;
            rs += c[i];
            count++;
            if(count == N - 1) break;
        }
    }
    cout << rs << endl;
}

void input(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u[i] >> v[i] >> c[i];
    }
}

int main(){
    input();
    solve();
}
