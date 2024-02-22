#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

bool dfs(std::vector<std::vector<std::pair<int, int>>>& G, int t, int v, int p, std::vector<int>& path) {
    if(v == t) {
        return true;
    }
    
    for(auto [nei, ei] : G[v]) {
        if(nei != p) {
            path.push_back(ei);
            if(dfs(G, t, nei, v, path)) {
                return true;
            }
            path.pop_back();
        }
    }

    return false;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<std::pair<int, int>>> G(N);
    std::vector<std::pair<int, int>> E(N - 1);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].emplace_back(V, i);
        G[V].emplace_back(U, i);
        E[i] = {U, V};
    }

    int K;
    std::cin >> K;
    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    std::vector<int> cover(N - 1);
    for(int i = 0; i < K; i++) {
        std::vector<int> path;
        dfs(G, A[i].second, A[i].first, -1, path);
        for(int e : path) {
            cover[e] |= 1 << i;
        } 
    }

    std::vector<int> s;
    for(int x : cover) {
        if(x) {
            s.push_back(x);
        }
    }

    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());

    int size = s.size();
    std::vector<int> dp(1 << K, INF);
    dp[0] = 0;
    for(int m = 0; m < (1 << K); m++) {
        if(dp[m] != INF) {
            for(int i = 0; i < size; i++) {
                if((m | s[i]) != m) {
                    dp[m | s[i]] = std::min(dp[m | s[i]], dp[m] + 1);
                } 
            }
        }
    }

    std::cout << dp[(1 << K) - 1] << '\n';
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
