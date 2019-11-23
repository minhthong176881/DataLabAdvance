#include<iostream>
#include<vector>
#include<queue>

#define Max_N 100001

using namespace std;

int N, M;
vector<int> A[Max_N];
int d[Max_N];

void input(){
    cin >> N >> M;
    for(int k = 1; k <= N; k++){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

int BFS(int s){
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    while(Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int x = 0; x < A[v].size(); x++){
            if(d[x] > -1){
                if(d[x] % 2 == d[A[v][x]] % 2) return 0;
            }
            else{
                Q.push(A[v][x]);
                d[A[v][x]] = d[v] + 1;
            }
        }
    }
    return 1;
}

int main(){
    input();
    int ans = 1;
    for(int i = 1; i <= N; i++){
        d[i] = -1;
    }
    for(int s = 1; s <= N; s++){
        if(d[s] == -1){
            if(BFS(s) == 0)
                ans = 0;
        }
    }
    cout << ans << endl;
    return 0;
}