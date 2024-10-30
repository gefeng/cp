#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void dfs(std::map<int64_t, std::vector<int64_t>>& g, int64_t v, std::set<int64_t>& vis, int64_t& ans) {
    vis.insert(v);
    ans = std::max(ans, v);

    if(g.find(v) != g.end()) {
        for(int64_t nei : g[v]) {
            if(vis.find(nei) == vis.end()) {
                dfs(g, nei, vis, ans);
            }
        }
    }
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<int64_t, std::vector<int64_t>> g;
    for(int i = 1; i <= N; i++) {
        int64_t u = A[i - 1] + i - 1;
        int64_t v = u + i - 1; 
        g[u].push_back(v);
    }

    std::set<int64_t> vis;
    int64_t ans = 0;
    dfs(g, int64_t(N), vis, ans);

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
