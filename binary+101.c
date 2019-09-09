#include <stdio.h>
int n;
int x[100];
// int c = 0;
int check(int *arr, int size){
  int valid  = 0;
  for (int i = 0; i < size - 2; i++)
  {
    if(arr[i] == 1 && arr[i + 1] == 0 && arr[i + 2] == 1 ) valid =1;
  }
  return valid;
}
 
void view(){
  // c++;
  // printf("[%.2d]: ",c);
  for(int i = 1; i <= n; i++){
    printf("%d ", x[i]);
  }
  printf("\n");
}
 
void TRY(int k){
  int v;
  for(v = 0; v <= 1; v++){
      x[k] = v;
      if(k == n) {
        if(check(x, n + 1))
          view();
      }
      else TRY(k + 1);
  }
}
 
int main(){
  n = 5;
  TRY(1);
}