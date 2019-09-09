#include <stdio.h>

int x[100];
int n;

int check(int v, int k) {
    // if((x[k - 2] == 1 && x[k - 1] == 0 && x[k] == 1) || (x[k + 2] == 1 && x[k + 1] == 0 && x[k] == 1))
	    return 1;
    // return 0;
}

void solution () {
	int i;
	for (i = 1; i <= n; i++) {
		printf ("%d", x[i]);
    }
	printf ("\n");
}

void TRY(int k) {
	int v;
	for(v = 0; v <= 1; v++) {
		if(check (v, k)) {
			x[k] = v;
			if(k == n) solution ();
			else TRY(k + 1);
		}
	}
}

int main () {
	n = 5;
	TRY(1);
	return 0;
}