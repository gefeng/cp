#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;
constexpr int MAX = (int)2e5;

std::vector<int64_t> fact(MAX + 1, 1);
std::vector<int64_t> invf(MAX + 1, 1);

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

int64_t dfs(std::vector<std::vector<int>>& G, int v, std::vector<int>& save_size) {
    int64_t res = 1;
    
    int sum_size = 0;
    for(int nei : G[v]) {
        res *= dfs(G, nei, save_size);  
        res %= MOD;
    
        sum_size += save_size[nei];
        res *= invf[save_size[nei]];
        res %= MOD;
    }

    res *= fact[sum_size];
    res %= MOD;

    save_size[v] = sum_size + 1;

    return res;
}

void run_case() {
    int N, M1, M2;
    std::cin >> N >> M1 >> M2;
    
    std::vector<int> A(M1);
    std::vector<int> B(M2);
    
    for(int i = 0; i < M1; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < M2; i++) {
        std::cin >> B[i];
        B[i] -= 1;
    }

    if(A.back() != B[0] || A[0] != 0 || B.back() != N - 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::vector<int>> G(N);
    for(int i = M1 - 2; i >= 0; i--) {
        G[A[i + 1]].push_back(A[i]);
        
        for(int j = A[i] + 1; j < A[i + 1]; j++) {
            G[A[i]].push_back(j);
        }
    }

    for(int i = 1; i < M2; i++) {
        G[B[i - 1]].push_back(B[i]);
        
        for(int j = B[i - 1] + 1; j < B[i]; j++) {
            G[B[i]].push_back(j);
        }
    }
    
    std::vector<int> save_size(N, 0);
    std::cout << dfs(G, A.back(), save_size) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
