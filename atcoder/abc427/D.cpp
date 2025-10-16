#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int dfs(int K, std::vector<std::vector<int>>& G, std::string& S, int v, int k, int t, 
        std::vector<std::vector<std::vector<int>>>& dp) {
    if(k == K) {
        return S[v] == 'A' ? 1 : 0;
    } 

    if(dp[t][k][v] != -1) {
        return dp[t][k][v];
    }

    int res = 0;
    if(t == 0) {
        for(int nei : G[v]) {
            if(!dfs(K, G, S, nei, k, t ^ 1, dp)) {
                res = 1;
            }
        }    
    } else {
        for(int nei : G[v]) {
            if(!dfs(K, G, S, nei, k + 1, t ^ 1, dp)) {
                res = 1;
            }
        }
    }

    return dp[t][k][v] = res;
}

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::string S;
    std::cin >> S;

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V;
        std::cin >> U >> V;
        
        U -= 1;
        V -= 1;

        G[U].push_back(V);
    }

    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(K, std::vector<int>(N, -1)));
    int res = dfs(K, G, S, 0, 0, 0, dp);

    std::cout << (res ? "Alice" : "Bob") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
