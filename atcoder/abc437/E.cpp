#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void dfs(std::vector<std::vector<std::pair<int, int>>>& G, std::vector<int>& now, std::vector<int>& ans) {
    std::vector<std::pair<int, int>> c;
    for(int v : now) {
        for(auto [u, w] : G[v]) {
            c.emplace_back(u, w);
        }
    }
    int n = c.size();

    std::ranges::sort(c, [](const auto& x, const auto& y) {
                if(x.second == y.second) {
                    return x.first < y.first;
                }
                return x.second < y.second;
            });

    for(int i = 0; i < n; ) { 
        int j = i;
        std::vector<int> nxt;
        while(i < n && c[j].second == c[i].second) {
            ans.push_back(c[i].first);
            nxt.push_back(c[i].first);
            i += 1; 
        }

        dfs(G, nxt, ans);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<std::pair<int, int>>> G(N + 1);
    
    for(int i = 1; i <= N; i++) {
        int P, X;
        std::cin >> P >> X;
        
        G[P].emplace_back(i, X);
    }

    
    std::vector<int> ans;
    std::vector<int> now(1, 0);
    dfs(G, now, ans);

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
