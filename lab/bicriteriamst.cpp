#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, profit, weight;
    double cost;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        return true;
    }
};

bool check(double lambda, const vector<Edge>& edges, int n, long long& total_profit, long long& total_weight) {
    vector<Edge> adjusted_edges = edges;
    for (auto& edge : adjusted_edges)
        edge.cost = edge.weight * lambda - edge.profit;

    sort(adjusted_edges.begin(), adjusted_edges.end(), [](const Edge& a, const Edge& b) {
        return a.cost < b.cost;
    });

    DSU dsu(n);
    total_profit = 0;
    total_weight = 0;

    int count = 0;
    for (const auto& edge : adjusted_edges) {
        if (dsu.unite(edge.u, edge.v)) {
            total_profit += edge.profit;
            total_weight += edge.weight;
            if (++count == n - 1) break;
        }
    }
    return total_weight > 0 && total_profit * 1.0 / total_weight >= lambda;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, p, w;
        cin >> u >> v >> p >> w;
        u--; v--; 
        edges[i] = {u, v, p, w, 0.0};
    }

    double low = 0, high = 1e9;
    long long best_profit = 0, best_weight = 1;

    for (int iter = 0; iter < 40; iter++) {
        double mid = (low + high) / 2.0;
        long long total_profit, total_weight;
        if (check(mid, edges, n, total_profit, total_weight)) {
            best_profit = total_profit;
            best_weight = total_weight;
            low = mid;
        } else {
            high = mid;
        }
    }

    long long g = gcd(best_profit, best_weight);
    cout << best_profit / g << " " << best_weight / g << "\n";

    return 0;
}