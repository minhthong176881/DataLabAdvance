#include <iostream>
#include <vector>
#define MAX_N 201
#define MAX 1000001

int N;
int M;
int K;
int Q;

using namespace std;

vector<int> A[MAX_N];
vector<int> w1[MAX_N];
vector<int> w2[MAX_N];
int visited[MAX_N] = {0};
int X[MAX_N];
int ans = MAX;
int rs1 = 0;
int rs2 = 0;

int check(int v, int k)
{
    if (visited[v])
        return 0;
    return 1;
}

void TRY(int k)
{
    for (int i = 0; i < A[X[k - 1]].size(); i++)
    {
        int v = A[X[k - 1]][i];
        if (check(v, k))
        {
            X[k] = v;
            rs1 += w1[X[k - 1]][i];
            rs2 += w2[X[k - 1]][i];

            visited[v] = 1;
            if (k == K + 1)
            {
                if (rs1 < ans && rs2 <= Q)
                {
                    ans = rs1;
                }
            }
            else
            {
                if (rs1 + (K + 1 - k) < ans && rs2 +  (K + 1 - k) <= Q)
                    TRY(k + 1);
            }
            rs1 -= w1[X[k - 1]][i];
            rs2 -= w2[X[k - 1]][i];
            visited[v] = 0;
        }
    }
}

void input()
{
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= M; i++)
    {
        int x, y, wg1, wg2;
        cin >> x >> y >> wg1 >> wg2;
        A[x].push_back(y);
        A[y].push_back(x);
        w1[x].push_back(wg1);
        w1[y].push_back(wg1);
        w2[x].push_back(wg2);
        w2[y].push_back(wg2);
    }
}

int main()
{
    input();
    for (int v = 1; v <= N; v++)
    {
        X[1] = v;
        visited[v] = true;
        TRY(2);
        visited[v] = false;
    }
    cout << ans << endl;
}

/*
5 7 3 6 
1 2 1 2 
1 4 2 2
1 5 3 6
2 3 3 2
2 4 4 4
3 4 5 1
4 5 4 7 
*/

// if (rs1 + cmin1 * (K + 1 - k) < ans && rs2 + cmin2 * (K + 1 - k) <= Q)