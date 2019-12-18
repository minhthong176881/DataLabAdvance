#include<iostream>
#include<vector>
#include<set>
#define Max 1000001

using namespace std;

int N,M,K;
int u[Max];
int v[Max];
int c[Max];
int ET[Max];
int nET;
int numE[Max]={0};

int r[Max];//rank
int p[Max];//parent
long long rs;

void link(int x, int y){
    if(r[x]>r[y]) p[y]=x;
    else{
        p[x]=y;
        if(r[x]==r[y]) r[y]=r[y]+1;
    }
}

void makeSet(int x){
    p[x]=x;
    r[x]=0;
}

int findSet(int x){
    if(x!=p[x]) p[x]=findSet(p[x]);
    return p[x];
}
void swap(int &a, int &b){
    int tmp=a;
    a=b;
    b=tmp;
}

void swapEdge(int i, int j){
    swap(c[i],c[j]);
    swap(u[i],u[j]);
    swap(v[i],v[j]);
}

int partition(int L, int R, int index){
    int pivot=c[index];
    swapEdge(index,R);
    int storeIndex=L;
    for(int i=L;i<=R;i++){
        if(c[i]<pivot){
            swapEdge(storeIndex,i);
            storeIndex++;
        }
    }
    swapEdge(storeIndex,R);
    return storeIndex;
}

void quicksort(int L, int R){
    if(L<R){
        int index=(L+R)/2;
        index=partition(L,R,index);
        if(L<index) quicksort(L,index-1);
        if(index<R) quicksort(index+1,R);
    }
}
void quickSort(){
    quicksort(0,M-1);
}

void solve(){
    for(int x=1;x<=N;x++) makeSet(x);
    quickSort();
    rs=0;
    int count=0;
    nET=0;
    for(int i=0;i<M;i++){
        int ru=findSet(u[i]);
        int rv=findSet(v[i]);
        if(ru!=rv){
            /*if(numE[ru]==0) numE[rv]++;
            else numE[rv]+=numE[ru];
            if(numE[rv]>K){
                numE[rv]-=numE[ru];
                continue;
            }*/
            link(ru,rv);
            nET++; ET[nET]=1;
            rs+=c[i];
            //if(numE[rv]==K) break;
            count++;
            if(count==K) break;
        }
    }
    cout << rs << endl;
}

void input(){
    cin >> N >> M >> K;
    for(int i=0;i<M;i++){
        cin >> u[i] >> v[i] >> c[i];
        /*
        int iu,iv,iw;
        cin >> iu >> iv >> iW;
        u[i]=iu;
        v[i]=iv;
        c[i]=iw;
        if(u[i]>v[i]) swap(u[i],v[i]);
        */
    }
}

int main(){
    input();
    solve();
}