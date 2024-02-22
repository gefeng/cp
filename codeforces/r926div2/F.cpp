#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

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

void dfs(std::vector<std::pair<int, int>>& G, std::vector<int>& A, int v, std::vector<int>& a) {
    if(G[v].first != -1) {
        dfs(G, A, G[v].first, a);
    }

    a.push_back(A[v]);

    if(G[v].second != -1) {
        dfs(G, A, G[v].second, a);
    }
}

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::vector<std::pair<int, int>> G(N);
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        int L, R, V;
        std::cin >> L >> R >> V;

        if(L == -1) {
            G[i].first = -1;
        } else {
            G[i].first = L - 1;
        }

        if(R == -1) {
            G[i].second = -1;
        } else {
            G[i].second = R - 1;
        }

        A[i] = V; 
    }

    std::vector<int> a;
    dfs(G, A, 0, a);

    int64_t ans = 1;
    int l = 1;
    for(int i = 0; i < N; ) {
        if(a[i] != -1) {
            l = a[i++];
        } else {
            int j = i;
            while(i < N && a[i] == -1) {
                i += 1; 
            }

            int r = i == N ? C : a[i]; 
            int len = i - j;

            int64_t comb = 1;
            for(int64_t x = r - l + len; x >= r - l + 1; x--) {
                comb *= x;
                comb %= MOD;
            }

            int64_t f = 1;
            for(int64_t x = 1; x <= len; x++) {
                f *= x;
                f %= MOD;
            }

            comb *= q_pow(f, MOD - 2);
            comb %= MOD;

            ans *= comb;
            ans %= MOD;
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
