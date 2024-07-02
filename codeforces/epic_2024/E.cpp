#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <tuple>

constexpr int64_t INF = (int64_t)2e18;

// return nodes {depth, A[v] - sum(A[vc])}
std::set<std::tuple<int, int, int64_t>> dfs(std::vector<std::vector<int>>& G, std::vector<int64_t>& A, int v, int d, int64_t& ans) {
    std::set<std::tuple<int, int, int64_t>> s;

    if(G[v].empty()) {
        s.emplace(d, v, INF);
        return s;
    }
    
    int64_t sum = 0;
    for(int nei : G[v]) {
        std::set<std::tuple<int, int, int64_t>> ret = dfs(G, A, nei, d + 1, ans);
        if(ret.size() > s.size()) {
            std::swap(ret, s);
        }
        for(auto& [x, _, y] : ret) {
            s.emplace(x, _, y);
        }
        sum += A[nei];
    }

    if(A[v] <= sum) {
        if(A[v] < sum) {
            s.emplace(d, v, sum - A[v]);
        }  
    } else {
        int64_t need = A[v] - sum;
        while(need) {
            auto [x, v, y] = *s.begin();
            if(y == INF) {
                ans += (int64_t)(x - d) * need;
                need = 0;
            } else {
                int64_t offer = std::min(need, y);
                ans += (int64_t)(x - d) * offer;
                need -= offer;
                s.erase({x, v, y});
                if(y > offer) {
                    y -= offer;
                    s.emplace(x, v, y);
                } 
            }
        }
    }

    return s;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i + 1);
    }

    int64_t ans = 0;
    dfs(G, A, 0, 0, ans); 
    
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
