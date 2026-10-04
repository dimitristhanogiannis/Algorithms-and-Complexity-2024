#include <bits/stdc++.h>

using namespace std;

int random(int min, int max){
    srand(time(0));

    return min + rand()% ((max + 1) - min);
}

int partition(int *A, int left, int right){
    int i = left;
    int j = right;
    int pivot = A[left];

    while(1){
        while(A[i] < pivot) i++;
        while(A[j] > pivot) j--;
            
        if (i >= j) return j;
        swap(A[i], A[j]);
        i++;
        j--; 
    }
}

void quicksort(int *A, int left, int right){
    if(left >= right) return;
    int q = partition(A, left, right);
    quicksort(A, left, q);
    quicksort(A, q + 1, right);
}

void randomquicksort(int *A, int left, int right){
    if(left >= right) return;
    int pivot = random(left, right);
    swap(A[left], A[pivot]);
    int q = partition(A, left, right);
    randomquicksort(A, left, q);
    randomquicksort(A, q + 1, right);
}

int main(){
    int n;

    cin >> n;

    int A[n + 1];

    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }

    //quicksort(A, 1, n);
    randomquicksort(A, 1, n);

    for (int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }

}