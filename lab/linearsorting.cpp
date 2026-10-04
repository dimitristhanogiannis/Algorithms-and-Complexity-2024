#include <bits/stdc++.h>

using namespace std;

void countingsort(int *A, int *B, int n){
    int k = -1;

    for (int i = 1; i <= n; i++){
        if (A[i] > k) k = A[i];
    }

    int C[k];

    for (int i = 0; i <= k; i++){
        C[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        C[A[i]] ++;
    }

    for (int i = 1; i <= k; i++){
        C[i] += C[i - 1];
    }

    for (int i = n; i >= 1; i--){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

}

void bucketsort(int *A, int *B, int n){
    int k = -1;

    for (int i = 1; i <= n; i++){
        if (A[i] > k) k = A[i];
    }

    int C[k];

    for (int i = 0; i <= k; i++){
        C[i] = 0;
    }

    for (int i = 1; i <= n; i++){
        C[A[i]] ++;
    }

    int pos = 1;

    for (int i = 0; i <= k; i++){
        while(C[i] != 0) {
            B[pos] = i;
            pos++;
            C[i]--;
        }
    }
}

void helpfullcountingsort(int *A, int *B, int n, int exp){
    int C[10] = {0};

    for(int i = 1; i <= n; i++){
        int digit = (A[i] / exp) % 10;
        C[digit]++;
    }

    for (int i = 1; i < 10; i++){
        C[i] += C[i - 1];
    }

    for(int i = n; i >= 1; i--){
        int digit = (A[i] / exp) % 10;
        B[C[digit]] = A[i];
        C[digit]--;
    }

    for (int i = 1; i <= n; i++){
        A[i] = B[i];
    }
}

void radixsort(int *A, int n){
    int B[n + 1];
    int maxval = A[1];

    for(int i = 2; i <= n; i++){
        if(A[i] > maxval) maxval = A[i];
    }

    for(int exp = 1; maxval / exp > 0; exp *= 10) {
        helpfullcountingsort(A, B, n, exp);
    }
}

int main(){
    int n;

    cin >> n;

    int A[n + 1], B[n + 1];

    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }

    //countingsort(A, B, n);
    //bucketsort(A, B, n);
    radixsort(A, n);

    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
}