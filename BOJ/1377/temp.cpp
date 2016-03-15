#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int A[1111];
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
int i,j,temp;
int change;
for (i=1; i<=N; i++){
    change = 0;
       for (int i = 1; i <= N; i++) printf("%d ", A[i]); printf(" -> ");
    for (j=1; j<=N-i; j++){
        if(A[j] > A[j+1]){
            change = 1;
            swap(A[j], A[j + 1]);
        }
    }
	for (int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
    if (change == 0) {
        break;
    }
}
printf("%d\n",i);
	return 0;
}