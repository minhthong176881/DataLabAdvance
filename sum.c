// #include <stdio.h>

// int x[100];
// int appear[100];
// int n;

// int check(int v, int k) {
//     if(appear[v] && x[k] == v) return 0;
// 	return 1;
// }

// void init(){
// 	int v;
// 	for(v = 1; v <= n; v++){
// 		appear[v] = 0;
// 	}
// }

// int checkSolution(){
// 	int count = 0;
// 	for(int i = 1; i <= n; i++){
// 		count += x[i];
// 	}
// 	if(count == n) return 1;
// 	else return 0;
// }

// void solution () {
// 	int i;
// 	printf("%d = ", n);
// 	for (i = 1; i <= n - 1; i++) {
// 		printf("%d + ", x[i]);
// 		// printf("%d ", x[i]);
//     }
//     printf("%d\n", x[n]);
// }

// void TRY(int k) {
// 	int v;
// 	for(v = 1; v <= n; v++) {
// 		if(check (v, k)) {
// 			x[k] = v;
// 			appear[v] = 1;
// 			if(checkSolution()) solution ();
// 			else TRY(k + 1);
// 		}
// 		appear[v] = 0;}
// }

// int main () {
// 	init();
// 	n = 6;
// 	TRY(1);
// 	return 0;
// }

#include <stdio.h>
int n;
int x[100];
 
int check(int *arr, int size)
{
  int total = 0;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == 1)
      total = total + i + 1;
  }
  return total == size;
}
 
void solution(int *arr,int size)
{
  for (int i = 0; i < size; i++)
  {
    if(arr[i])
    printf("%d ", i + 1);
  }
  printf("\n");
}
 
void TRY(int k)
{
  int v;
  for (v = 0; v <= 1; v++)
  {
    x[k] = v;
    if (k == n - 1)
    {
      if (check(x, n))
        solution(x,n);
    }
    else
    {
      TRY(k + 1);
    }
  }
}
 
int main()
{
  printf("n = ");
  scanf("%d", &n);
  TRY(0);
}