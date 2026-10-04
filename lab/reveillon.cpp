#include <bits/stdc++.h>

using namespace std;

long long maximize_happiness(int N, int K, const vector<int>& h) {
    
    vector<long long> dp(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        
        int max_h = 0;

        for (int k = 1; k <= min(K, i); k++) {
            
            max_h = max(max_h, h[i - k]);
            dp[i] = max(dp[i], dp[i - k] + (long long)k * max_h);
        }
    }
    
    return dp[N];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;

    cin >> N >> K;
    
    vector<int> h(N);

    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    
    cout << maximize_happiness(N, K, h) << endl;

    return 0;
}