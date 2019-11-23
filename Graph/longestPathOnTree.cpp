#include<iostream>
#include<vector>
#include<queue>
#define Max_N 106

using namespace std;

int N;
int d[Max_N] = {-1};
vector<int> A[Max_N];
vector<int> W[Max_N];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

int BFS(int s){
    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int i = 0; i < A[v].size(); i++){
            int x = A[v][i];
            int w = W[v][i];
            if(d[x] == -1){
                Q.push(x);
                d[x] = d[v] + w;
            }
        }
    }
    int maxDis = 0;
    for(int i = 0; i < s; i++){
        if(d[i] > maxDis){
            maxDis = d[i];
        }
    }
    cout << maxDis << endl;
    return maxDis;
}

int main(){
    input();
    for(int s = 1; s <= N; s++){
        if(d[s] == -1){
            BFS(s);
        }
    }
    // int t1 = BFS(0);
    // int t2 = BFS(t1.first);
    return 0;
}