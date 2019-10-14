#include<stdio.h>
int a[1000005];
int n;
int m;

int countSubarrays(int arr[], int n, int m)
{
    int start = 0, end = 0, count = 0, sum = arr[0];
    while (start < n && end < n) {  
        if (sum <= m) {
            end++;
            if (end >= start)
                count += end - start;  
            if (end < n)
                sum += arr[end];
        }
        else {
            sum -= arr[start];
            start++;
        }
    }
    return count;
}

int main()
{
    scanf("%d %d",&n, &m);
    int i, j;
    int count = 0;
    for(i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    printf("%d\n", countSubarrays(a, n, m));
    return 0;
}
