#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int INF = static_cast<int>(2e9) + 10;

bool dfs1(int N, std::vector<std::vector<int>>& G, int v, std::vector<int>& path) {
    if(v == N - 1) {
        path.push_back(v);
        return true;
    }

    bool on_path = false;
    for(int nei : G[v]) {
        if(dfs1(N, G, nei, path)) {
            on_path = true;
        }
    }
    if(on_path) {
        path.push_back(v);
    }
    return on_path;
}

int dfs2(std::vector<std::vector<int>>& G, std::string& S, std::vector<int>& on_path, int v, std::vector<int>& dp) {
    int res = -1;
    for(int nei : G[v]) {
        if(on_path[nei]) {
            continue;
        }
        int x = dfs2(G, S, on_path, nei, dp);
        if(x == -1) {
            continue;
        }
        res = res == -1 ? x + 2 : res + x + 2;
    }
    
    if(S[v] == '1') {
        res = res == -1 ? 0 : res;
    }

    dp[v] = res;

    return res;
}


void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> G(N);
    for(int i = 1; i < N; i++) {
        int P;
        std::cin >> P;
        P -= 1;
        G[P].push_back(i);
    }
    
    std::string S;
    std::cin >> S;

    std::vector<int> path;
    dfs1(N, G, 0, path);
    std::ranges::reverse(path);

    std::vector<int> on_path(N, 0);

    int m = path.size();
    for(int i = 0; i < m; i++) {
        on_path[path[i]] = 1;
    }

    std::vector<int> dp(N, -1);
    for(int i = 0; i < m; i++) {
        dfs2(G, S, on_path, path[i], dp);
    }

    int ans = INF;
    std::vector<int> psum(m + 1, 0);
    for(int i = 0; i < m; i++) {
        psum[i + 1] = psum[i] + (dp[path[i]] == -1 ? 0 : dp[path[i]]);
    }

    std::vector<int> a;
    for(int i = 0; i < m; i++) {
        if(dp[path[i]] != -1) {
            a.push_back(i);
        }
    }

    int size = a.size();
    if(size == 0) {
        std::cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < size; i++) {
        int l = psum[a[i] + 1] + a[i] * 2;
        int r = i + 1 < size ? psum[m] - psum[a[i + 1]] + (m - 1 - a[i + 1]) * 2 : 0;
        ans = std::min(ans, l + r);
    }
    ans = std::min(ans, psum[m] - psum[a[0]] + (m - 1 - a[0]) * 2);
    
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
