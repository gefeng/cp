#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <ranges>
#include <numeric>

constexpr int INF = int(2e9);

int dfs(std::vector<std::vector<std::tuple<int, int, int>>>& G, 
        int v, int p, int64_t& sum, std::vector<std::tuple<int, int, int>>& e) {

    if(G[v].size() == 1 && p != -1) {
        return 1;
    }

    int cnt_leaf = 0;
    for(auto [nei, w, c] : G[v]) {
        if(nei != p) {
            int cnt = dfs(G, nei, v, sum, e);
            sum += int64_t(cnt) * w;
            e.emplace_back(w, cnt, c);
            cnt_leaf += cnt;
        }
    }

    return cnt_leaf;
}

void run_case() {
    int N;
    int64_t S;
    std::cin >> N >> S;

    std::vector<std::vector<std::tuple<int, int, int>>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V, W, C;
        std::cin >> U >> V >> W >> C;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, W, C);
        G[V].emplace_back(U, W, C);
    }

    std::vector<std::tuple<int, int, int>> e;
    int64_t sum = 0;
    dfs(G, 0, -1, sum, e);

    std::vector<int64_t> seq_1;
    std::vector<int64_t> seq_2;

    for(auto [w, d, c] : e) {
        while(w) {
            if(c == 1) {
                seq_1.push_back(int64_t(w - w / 2) * d);
            } else {
                seq_2.push_back(int64_t(w - w / 2) * d);
            }
            w /= 2;
        }
    }

    std::ranges::sort(seq_1, std::greater<int64_t>());
    std::ranges::sort(seq_2, std::greater<int64_t>());

    int ans = INF;
    int n = seq_1.size();
    int m = seq_2.size();
    int64_t prefix = 0;
    int64_t suffix = std::accumulate(seq_2.begin(), seq_2.end(), int64_t(0));
    for(int i = 0, j = m - 1; i <= n; i++) {
        int64_t t = std::max(int64_t(0), sum - S - prefix);
        while(j >= 0 && suffix - seq_2[j] >= t) {
            suffix -= seq_2[j--]; 
        } 

        t -= suffix;
        if(t <= 0) {
            ans = std::min(ans, i + (j + 1) * 2);
        }

        if(i != n) {
            prefix += seq_1[i];
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
