#include <iostream>
#include <list>
using namespace std;
const long MAX=1000005;
long long n, s0[MAX], s1[MAX], ans = -1000000, a[MAX];


int main(){
	cin >> n;
    s0[0] = 0;
    s1[0] = -1000000;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0){
		    s0[i] = a[i];
		    s1[i] = -1000000;
		    if(s0[i - 1] + a[i] > s0[i]) s0[i] = s0[i - 1] + a[i];
		    if(s1[i - 1] + a[i] > s1[i]) s1[i] = s1[i - 1] + a[i];
	    }
		else {
			s1[i] = a[i];
			s0[i] = -1000000;
			if(s0[i - 1] + a[i] > s1[i]) s1[i] = s0[i - 1] + a[i];
		    if(s1[i - 1] + a[i] > s0[i]) s0[i] = s1[i - 1] + a[i];
		}
		if(ans < s0[i]) ans = s0[i];
	}
	cout<<ans;
}