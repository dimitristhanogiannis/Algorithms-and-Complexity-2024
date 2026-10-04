#include <bits/stdc++.h>

using namespace std;

vector<int> A;
int hs; //heap size

int max(){
    return A[1];
}

int size(){
    return hs;
}

bool isEmpty(){
    return hs == 0;
}

void combine(int i){
    int l = 2*i;
    int r = 2*i+1;
    int mp = i; //max position

    if ((l <= hs) && (A[l] > A[mp])) mp = l;
    if ((r <= hs) && (A[r] > A[mp])) mp = r;

    if (mp != i){
        swap(A[i], A[mp]);
        combine(mp);
    } 
}

int deleteMax(){
    if (A.empty()) return -1;

    int max = A[1];

    A[1] = A[hs--];
    combine(1);
    return max;
}

void insert(int k){
    if (hs + 1 >= A.size()) A.resize(hs + 2);

    A[++hs] = k;
    int i = hs;
    int p = i / 2;
    
    while((i > 1) && (A[p] < A[i])){
        swap(A[p],A[i]);
        i = p;
        p = i / 2;
    }
}

void constructHeap(int n){
    hs = n; 
    for (int i = n/2; i > 0; i--){
        combine(i);
    }
}

int main(){
    int n;

    cin >> n;

    A.resize(n + 1); // για να ξεκιναει η αριθμηση απο το 1 οπως ζητειται

    for (int i = 1; i <= n; i++){
        cin >> A[i];
    }

    constructHeap(n);

    for (int i = 1; i <= hs; i++){
        cout << A[i] << " ";
    }

    cout << endl;

    cout << max() << endl;

    cout << size() << endl;

    int max = deleteMax();

    for (int i = 1; i <= hs; i++){
        cout << A[i]  << " ";
    }

    cout << endl;

    cout << max << endl;

    int insertion;

    cin >> insertion;

    insert(insertion);

    for (int i = 1; i <= hs; i++){
        cout << A[i]  << " ";
    }

    return 0;
}