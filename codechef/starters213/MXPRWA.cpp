#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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

void dfs(std::vector<std::vector<int>>& G, std::vector<int>& A, int v, int p, 
        std::vector<int>& dp1, std::vector<int>& dp2, std::vector<int64_t>& dp3, std::vector<int>& par) {
    par[v] = p;
    for(int nei : G[v]) {
        if(nei != p) {
            dfs(G, A, nei, v, dp1, dp2, dp3, par);
            dp1[v] += dp1[nei];
            dp2[v] += dp2[nei];
            dp3[v] += dp3[nei];
        }
    }
    dp3[v] += std::abs(A[v]);
    if(A[v] < 0) {
        dp1[v] += 1;
    } else {
        dp2[v] += 1;
    }
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

    int neg = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            neg += 1; 
        }
    }

    int64_t ans = 0;
    int64_t max_w = 0;
    if(neg % 2 == 0) {
        for(int i = 0; i < N; i++) {
            max_w += std::abs(A[i]);
        }
    } else {
        std::vector<int> dp1(N, 0);
        std::vector<int> dp2(N, 0);
        std::vector<int64_t> dp3(N, 0);
        std::vector<int> par(N, -1);
        dfs(G, A, 0, -1, dp1, dp2, dp3, par);

        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                for(int nei : G[i]) {
                    if(nei == par[i]) {
                        if((dp1[0] - dp1[i]) % 2 == 1) {
                            max_w = std::max(max_w, dp3[0] - dp3[i] + A[i]);
                        } else {
                            max_w = std::max(max_w, dp3[0] - dp3[i]);
                        }
                    } else {
                        if(dp1[nei] % 2 == 1) {
                            max_w = std::max(max_w, dp3[nei] + A[i]);
                        } else {
                            max_w = std::max(max_w, dp3[nei]);       
                        }
                    }
                }
            }
        }
    }

    ans = q_pow(2, max_w);
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
