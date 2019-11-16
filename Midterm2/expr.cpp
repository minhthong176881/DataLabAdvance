#include<iostream>
using namespace std;

int X[100];
int n, m;
int a[100];
int c = 0;

void input(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
}

int check(int v, int k)
{
	return 1;
}

void solution()
{
	int sum = a[1];
	for(int i = 2; i <= n; i++){
		if(X[i] == 0) sum = sum - a[i];
		else if(X[i] == 1) sum = sum + a[i];
	}
	if(sum == m) c++;
	sum = a[1];
}
void TRY(int k)
{
	int v;
	for(v = 0; v <= 1; v++)
	{
		if(check(v, k))
		{
			X[k] = v;
			if(k == n) solution();
			else TRY(k + 1);
		}
	}
}
int main()
{
	input();
	TRY(2);
	cout << c << endl;
	return 0; 
}