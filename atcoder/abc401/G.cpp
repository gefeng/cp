#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

constexpr long double MAX = 4e18;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    std::vector<FlowEdge> edges;
    std::vector<std::vector<int>> adj;
    int n, m = 0;
    int s, t;
    std::vector<int> level, ptr;
    std::queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap == edges[id].flow)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u])
                continue;
            long long tr = dfs(u, std::min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    std::vector<std::pair<int64_t, int64_t>> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    auto check = [&](int i, int j, long double threshold) {
        auto [x_1, y_1] = A[i];
        auto [x_2, y_2] = B[j];

        long double x = x_1 - x_2;
        long double y = y_1 - y_2;
        
        return x * x + y * y <= threshold * threshold;
    };

    long double lo = 0;
    long double hi = MAX;
    long double ans = 0;
    
    for(int _ = 0; _ < 100; _++) {
        long double mid = (lo + hi) / 2.0;
        
        Dinic max_flow(N * 2 + 2, 0, N * 2 + 1);
        for(int i = 0; i < N; i++) {
            max_flow.add_edge(0, i + 1, 1);
            max_flow.add_edge(i + N + 1, N * 2 + 1, 1);
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(check(i, j, mid)) {
                    max_flow.add_edge(i + 1, j + N + 1, 1);
                }
            }
        }

        if(max_flow.flow() == N) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
