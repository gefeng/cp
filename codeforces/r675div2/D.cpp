#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <queue>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    int SX, SY, TX, TY;
    std::cin >> SX >> SY >> TX >> TY;


    std::vector<std::pair<int, int>> A(M);
    std::map<int, int> row;
    std::map<int, int> col;
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
        row[A[i].first] = 0;
        col[A[i].second] = 0;
    }

    int64_t ans = std::abs(TX - SX) + std::abs(TY - SY);
    if(M == 0) {
        std::cout << ans << '\n';
        return;
    }
    
    int n = 0;
    int m = 0;
    int x = M;
    for(auto& [_, id] : row) {
        id = x++;
        n += 1;
    }

    for(auto& [_, id] : col) {
        id = x++;
        m += 1;
    }

    int size = n + m + M + 2;
    std::vector<std::vector<std::pair<int, int>>> g(size);
    for(int i = 0; i < M; i++) {
        auto [r, c] = A[i];
        g[i].emplace_back(row[r], 0);
        g[row[r]].emplace_back(i, 0);
        g[i].emplace_back(col[c], 0);
        g[col[c]].emplace_back(i, 0);
        auto it = row.upper_bound(r);
        if(it != row.end()) {
            g[i].emplace_back(it->second, it->first - r);
            g[it->second].emplace_back(i, it->first - r);
        }
        it = col.upper_bound(c);
        if(it != col.end()) {
            g[i].emplace_back(it->second, it->first - c);
            g[it->second].emplace_back(i, it->first - c);
        }
    }

    {
        auto it = row.lower_bound(SX);
        if(it != row.end()) {
            g[size - 2].emplace_back(it->second, it->first - SX);
        }
        if(it != row.begin()) {
            it = std::prev(it);
            g[size - 2].emplace_back(it->second, SX - it->first);
        }

        it = col.lower_bound(SY);
        if(it != col.end()) {
            g[size - 2].emplace_back(it->second, it->first - SY);
        }
        if(it != col.begin()) {
            it = std::prev(it);
            g[size - 2].emplace_back(it->second, SY - it->first);
        }
    }

    auto cmp = [](const auto& x, const auto& y) {
        return x.second > y.second;
    };
    std::priority_queue<std::pair<int, int64_t>, std::vector<std::pair<int, int64_t>>, decltype(cmp)> pq(cmp); 
    std::vector<int64_t> best(size, INF);
    pq.emplace(size - 2, 0);
    best[size - 2] = 0;
    while(!pq.empty()) {
        auto [v, d] = pq.top();
        pq.pop();
        if(d != best[v]) {
            continue;
        }
        for(auto [nei, w] : g[v]) {
            if(best[nei] > d + w) {
                best[nei] = d + w;
                pq.emplace(nei, d + w);
            }
        }
    }

    for(int i = 0; i < M; i++) {
        auto [r, c] = A[i];
        if(best[i] != INF) {
            ans = std::min(ans, std::abs(r - TX) + std::abs(c - TY) + best[i]);
        } 
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
