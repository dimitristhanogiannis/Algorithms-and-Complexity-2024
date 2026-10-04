#include <bits/stdc++.h>

using namespace std;

vector<int> match;
vector<int> BIT;
int N;

int sum(int Y) { //SUM 1 Y
    int answer = 0;
    while (Y > 0){
        answer += BIT[Y];
        Y -= (Y & -Y);
    }
    return answer;
}

int sum(int X, int Y){
    return sum(Y) - sum(X - 1);
}

void add(int pos, int num){
    while (pos <= N){
        BIT[pos] += num;
        pos += (pos & -pos);
    }
}

int main(){

    cin >> N;

    match.resize(N + 1);
    BIT.resize(N + 1);

    for (int i = 1; i <= N; i++){
        cin >> match[i];
        int last_one = (i & -i);
        for (int j = i; j >= (i - last_one + 1); j--){
            BIT[i] += match[j];
        } 
    }

    for (int i = 1; i <= N; i++){
        cout << BIT[i] << " ";
    }
      
    cout << endl;  

    cout << sum(11) << endl;

    add(5, 3);

    for (int i = 1; i <= N; i++){
        cout << BIT[i] << " ";
    }

    return 0;
}