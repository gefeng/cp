#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

int dfs(std::vector<std::vector<std::pair<int, int>>>& G, int v, int p, int64_t& sum, std::vector<std::pair<int, int>>& e) {
    if(G[v].size() == 1 && p != -1) {
        return 1;
    }

    int cnt_leaf = 0;
    for(auto [nei, w] : G[v]) {
        if(nei != p) {
            int cnt = dfs(G, nei, v, sum, e);
            sum += int64_t(cnt) * w;
            e.emplace_back(w, cnt);
            cnt_leaf += cnt;
        }
    }

    return cnt_leaf;
}

void run_case() {
    int N;
    int64_t S;
    std::cin >> N >> S;

    std::vector<std::vector<std::pair<int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W;
        std::cin >> U >> V >> W;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W);
        G[V].emplace_back(U, W);
    }

    auto cmp = [](const auto& x, const auto& y) {
        return int64_t(x.second) * (x.first - x.first / 2) < int64_t(y.second) * (y.first - y.first / 2);
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);
    std::vector<std::pair<int, int>> e;
    int64_t sum = 0;
    dfs(G, 0, -1, sum, e);

    for(auto [v, c] : e) {
        pq.emplace(v, c);
    }

    int ans = 0;
    while(sum > S) {
        auto [w, c] = pq.top(); 
        pq.pop();

        ans += 1;
        
        sum -= int64_t(w - w / 2) * c;
        
        w /= 2;
        if(w) {
            pq.emplace(w, c);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
