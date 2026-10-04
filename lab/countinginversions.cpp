#include <bits/stdc++.h>

using namespace std;

int mergeandcount(int *A, int *B, int n){

}

int sortandcount(int *A, int n){
    if (n = 1) return 0;

    int B[(n/2) + 1];
    int C[(n/2) + 1];

    for (int i = 1; i <= n/2; i++){
        B[i] = A[i];
    }

    for (int i = n/2; i <= n; i++){
        C[i] = A[i];
    }

    sort(B, B + n/2);
    sort(C, C + n/2);

    int r1 = sortandcount(B, n/2);
    int r2 = sortandcount(C, n/2);

    int r = mergeandcount(B, C, n/2);
    
    return r1 + r2 + r;
}

int main(){
    int n;

    cin >> n;

    int A[n + 1];

    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }

    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
}