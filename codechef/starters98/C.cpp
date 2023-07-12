#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)(1e9 + 7);
constexpr int MAX = (int)2e6;

std::vector<int64_t> fact;
std::vector<int64_t> invf;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, std::vector<int64_t>& dp1, std::vector<int64_t>& dp2) {
    int64_t res = 1;
    int64_t x = 1;
    int64_t y = 0;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, A, nei, v, dp1, dp2);       
            res *= dp1[nei];
            res %= MOD;
            x *= invf[dp2[nei]];
            x %= MOD;
            y += dp2[nei];
        }
    }


    if(A[v]) {
        x *= invf[A[v]];
        x %= MOD;
        y += A[v];
    }

    res *= fact[y] * x % MOD; 
    res %= MOD;
    
    dp1[v] = res;
    dp2[v] = y ? y + 1 : y;

}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> G(N);
    for(int i = 0; i < N - 1; i++) {
        int U, V;
        std::cin >> U >> V;
        U -= 1;
        V -= 1;
        G[U].push_back(V);
        G[V].push_back(U);
    }
    
    std::vector<int64_t> dp1(N, 0);
    std::vector<int64_t> dp2(N, 0);
    dfs(G, A, 0, -1, dp1, dp2);

    std::cout << dp1[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    fact.resize(MAX + 1, 1);
    invf.resize(MAX + 1, 1);

    for(int i = 2; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 2; i <= MAX; i++) {
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
