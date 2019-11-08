#include<iostream>
#include<vector>

#define MAX_N 10000001
using namespace std;

int N, M; //number of nodes and edges
vector<int> A[MAX_N]; //A[x] is the list of 

//data structure for BFS
int d[MAX_N]; //d[v] is the printing time point of v
int f[MAX_N]; //f[v] is the visiting time point of v
int p[MAX_N]; //p[v] is the predecensor of v
char color[MAX_N]; //color[v] is the color of node v
int t; // global discrete time point (augmented by 1 each step)
int nbCC;

void DFS(int u){
    t = t + 1;
    d[u] = t;
    color[u] = 'G';
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i]; // v is an adjescent node to u
        if(color[v] == 'W'){
            p[v] = u;
            DFS(v);
        }
    }
    t = t + 1;
    f[u] = t; 
    color[u] = 'B'; //finished exploration of u
}

void DFS(){
    for(int u = 1; u <= N; u++){
        color[u] = 'W'; //not visited
    }
    nbCC = 0;
    for(int u = 1; u <= N; u++) 
        if(color[u] == 'W'){
            nbCC++;
            DFS(u); 
        }
    // for(int u = 1; u <= N; u++){
    //     cout << "d[" << u << "] = " << d[u] << ", f[" << u << "] = " << f[u] << ", p[" << u << "] = " << p[u] << endl;
    // }
    cout << nbCC << endl;
}

void input(){
    cin >> N >> M;
    for(int k = 1; k <= M; k++){
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}

void printGraph(){
    for(int u = 1; u <= N; u++){
        cout << "A[" << u << "] = ";
        for(int i = 0; i < A[u].size(); i++){
            cout << A[u][i] << " ";
        }
        cout << endl;
    }
}

int main(){
    input();
    // printGraph();
    DFS();
    return 0;
}