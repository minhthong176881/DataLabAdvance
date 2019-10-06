#include<stdio.h>
#include<iostream>
#include<list>
#define MAX 1000

using namespace std;

int map[MAX][MAX];
int level[MAX][MAX];
int N,M;
int i,j;
int ans;
list<int> qx;
list<int> qy;

void input(){
	scanf("%d %d %d %d",&N,&M,&i,&j);
	for(int n=1;n<=N;n++){
		for(int m=1;m<=M;m++){
			scanf("%d",&map[n][m]);
		}
	}
}

int goal(int x, int y){
    return x==1||x==N||y==1||y==M;
} 

int MoveUp(int x, int y){
	if(map[x-1][y]) return 0;
	if(goal(x-1,y)){
        ans=level[x][y]+2;
        return 1;
    }
    qx.push_back(x-1);
    qy.push_back(y);
    map[x-1][y]=1;
    level[x-1][y]=level[x][y]+1;
    return 0;
}

int MoveDown(int x, int y){
	if(map[x+1][y]) return 0;
	if(goal(x+1,y)){
        ans=level[x][y]+2;
        return 1;
    }
    qx.push_back(x+1);
    qy.push_back(y);
    map[x+1][y]=1;
    level[x+1][y]=level[x][y]+1;
    return 0;
}

int MoveLeft(int x, int y){
	if(map[x][y-1]) return 0;
	if(goal(x,y-1)){
        ans=level[x][y]+2;
        return 1;
    }
    qx.push_back(x);
    qy.push_back(y-1);
    map[x][y-1]=1;
    level[x][y-1]=level[x][y]+1;
    return 0;
}

int MoveRight(int x, int y){
	if(map[x][y+1]) return 0;
	if(goal(x,y+1)){
        ans=level[x][y]+2;
        return 1;
    }
    qx.push_back(x);
    qy.push_back(y+1);
    map[x][y+1]=1;
    level[x][y+1]=level[x][y]+1;
    return 0;
}

void solve(){
	qx.push_back(i);
	qy.push_back(j);
	level[i][j]=0;
	map[i][j]=1;
	ans=-1;
	while(!qx.empty()){
		int x=qx.front(); qx.pop_front();
        int y=qy.front(); qy.pop_front();
        if(MoveUp(x,y)) break;
        if(MoveDown(x,y)) break;
        if(MoveLeft(x,y)) break;
        if(MoveRight(x,y)) break;
	}
	printf("%d",ans);
}

int main(){
	input();
	solve();
	return 0;
}