#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2505;  
const int MAXK = 705;   
const long long INF = 1e18;

int N, K;
long long dp[MAXK][MAXN];
int opt[MAXK][MAXN];
long long presum[MAXN][MAXN];

long long getCost(int l, int r) {
    if (l >= r) return 0;
    
    long long result = presum[r][r];
    
    if (l > 0) {
        
        result -= presum[l-1][r];
        result -= presum[r][l-1];
        result += presum[l-1][l-1];
    }
    return result / 2;  
}

void compute() {
    
    for (int i = 0; i < N; i++) {
        
        dp[1][i] = getCost(0, i);
        opt[1][i] = 0;
    }
    
    for (int k = 2; k <= K; k++) {
        opt[k][N-1] = opt[k-1][N-1];
        
        for (int i = N-1; i >= k-1; i--) {
            dp[k][i] = INF;
            
            int left = (k-1 > 1) ? opt[k-1][i] : 0;
            int right = (i < N-1) ? min(i-1, opt[k][i+1]) : i-1;
            
            for (int j = left; j <= right; j++) {
                
                long long val = dp[k-1][j] + getCost(j+1, i);
                
                if (val < dp[k][i]) {
                    
                    dp[k][i] = val;
                    opt[k][i] = j;
                }
            }
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> K;
    
    if (N > MAXN || K > MAXK) {
        cerr << "Input exceeds array bounds\n";
        return 1;
    }
    
    memset(presum, 0, sizeof(presum));
    
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            
            long long x;  
            
            cin >> x;
            
            presum[i][j] = presum[j][i] = x;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) presum[i][j] += presum[i-1][j];
            if (j > 0) presum[i][j] += presum[i][j-1];
            if (i > 0 && j > 0) presum[i][j] -= presum[i-1][j-1];
        }
    }
    
    compute();

    cout << dp[K][N-1] << endl;
    
    return 0;
}