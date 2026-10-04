#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int to;
    int cost;
};

struct State {
    ll time;  
    int node; 
    int used; 
    bool operator>(const State &other) const {
        return time > other.time;
    }
};

int N, M, s, t;
ll B;
vector<vector<Edge>> graph;

bool canReach(int maxBoost) {
    vector<vector<ll>> d(N+1, vector<ll>(maxBoost+1, INF));
    d[s][0] = 0;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, s, 0});
    
    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();
        
        if(cur.time > B)
            continue;
            
        if(cur.node == t && cur.time <= B)
            return true;
        
        if(cur.time != d[cur.node][cur.used])
            continue;
        
        for(auto &edge : graph[cur.node]) {
            int newUsed = cur.used;
            ll newTime = cur.time + edge.cost;
            if(newTime < d[edge.to][newUsed] && newTime <= B) {
                d[edge.to][newUsed] = newTime;
                pq.push({newTime, edge.to, newUsed});
            }
            if(cur.used < maxBoost) {
                newUsed = cur.used + 1;
                newTime = cur.time; 
                if(newTime < d[edge.to][newUsed]) {
                    d[edge.to][newUsed] = newTime;
                    pq.push({newTime, edge.to, newUsed});
                }
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> s >> t >> B;
    graph.resize(N+1);
    for (int i = 0; i < M; i++){
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back({v, l});
    }
    
    int low = 0, high = N, ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(canReach(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}