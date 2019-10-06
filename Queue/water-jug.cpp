#include<stdio.h>
#include<iostream>
#include<list>
#define MAX 901

using namespace std;

int a,b,c;
int ans;
list<int> qx;
list<int> qy;
int visited[MAX][MAX]={0};//visited[i][j]=1 indicates that cell (i,j) has been visited
int level[MAX][MAX];//level[i][j] is the shortest distance from state(0,0) to state (i,j)

int goal(int x, int y){
    return x==c||y==c;
} 

int fillJug1(int x, int y){
    if(goal(a,y)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[a][y]) return 0;
    qx.push_back(a);
    qy.push_back(y);
    visited[a][y]=1;
    level[a][y]=level[x][y]+1;
    return 0;
}

int fillJug2(int x, int y){
    if(goal(x,b)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[x][b]) return 0;
    qx.push_back(x);
    qy.push_back(b);
    visited[x][b]=1;
    level[x][b]=level[x][y]+1;
    return 0;
}

int emptyJug1(int x, int y){
    if(goal(0,y)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[0][y]) return 0;
    qx.push_back(0);
    qy.push_back(y);
    visited[0][y]=1;
    level[0][y]=level[x][y]+1;
    return 0;                                                                           
}

int emptyJug2(int x, int y){
    if(goal(x,0)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[x][0]) return 0;
    qx.push_back(x);
    qy.push_back(0);
    visited[x][0]=1;
    level[x][0]=level[x][y]+1;
    return 0;                                                                           
}

int pourJug1toJug2(int x, int y){
    int nx,ny;
    if(x+y>b){
        nx=x+y-b;
        ny=b;
    }
    else{
        nx=0;
        ny=x+y;
    }
    if(goal(nx,ny)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[nx][ny]) return 0;
    qx.push_back(nx);
    qy.push_back(ny);
    visited[nx][ny]=1;
    level[nx][ny]=level[x][y]+1;
    return 0;
}

int pourJug2toJug1(int x, int y){
    int nx,ny;
    if(x+y>a){
        nx=a;
        ny=x+y-a;
    }
    else{
        nx=x+y;
        ny=0;
    }
    if(goal(nx,ny)){
        ans=level[x][y]+1;
        return 1;
    }
    if(visited[nx][ny]) return 0;
    qx.push_back(nx);
    qy.push_back(ny);
    visited[nx][ny]=1;
    level[nx][ny]=level[x][y]+1;
    return 0;
}

void solve(){
    qx.push_back(0);
    qy.push_back(0);
    level[0][0]=0;
    visited[0][0]=1;
    ans=-1;
    while (!qx.empty()){
        int x=qx.front(); qx.pop_front();
        int y=qy.front(); qy.pop_front();
        if(fillJug1(x,y)) break;
        if(fillJug2(x,y)) break;
        if(emptyJug1(x,y)) break;
        if(emptyJug2(x,y)) break;
        if(pourJug1toJug2(x,y)) break;
        if(pourJug2toJug1(x,y)) break;
    }
    printf("%d",ans);
}

int main(){
    scanf("%d %d %d",&a,&b,&c);
    solve();
    cout << endl;
    return 0;
}