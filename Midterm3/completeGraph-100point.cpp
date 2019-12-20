#include <iostream>
#define MAX_N 1001

using namespace std;

int N, M, K, A[MAX_N][MAX_N];

void input()
{
  cin >> N ;
  for (int i = 1; i <= N; i++)
  {
  	for (int j = 1; j <= N; j++)
  	{
      cin>>A[i][j];
    }
  }
}

int solution()
{
  for (int i = 1; i <= N; i++)
  {
  	for (int j = 1; j <= N; j++)
  	{
  		if(A[i][j] == 0 && A[j][i] == 0 && i != j)
  		return 0;
         
    }
  }
  return 1;
}

int main()
{
  input(); 
  cout << solution();
  return 0;
}