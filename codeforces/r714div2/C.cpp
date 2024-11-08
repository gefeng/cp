#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int MAX = int(2e5);

std::vector<int64_t> dp;

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::array<int64_t, 10> freq = {};
    
    int x = N;
    while(x) {
        freq[x % 10] += 1;
        x /= 10;
    }

    int64_t ans = 0;
    for(int i = 0; i < 10; i++) {
        int need = 10 - i;
        if(M >= need) {
            ans += dp[M - (10 - i)] * freq[i] % MOD;
            ans %= MOD;
        } else {
            ans += freq[i];
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp.resize(MAX + 1, 0);
    dp[0] = 2;

    std::array<int64_t, 10> freq = {};
    freq[0] = 1;
    freq[1] = 1;

    for(int i = 1; i <= MAX; i++) {
        std::array<int64_t, 10> nxt = {};
        for(int j = 0; j < 9; j++) {
            nxt[j + 1] += freq[j]; 
            nxt[j + 1] %= MOD;
        }
        
        nxt[0] += freq[9];
        nxt[0] %= MOD;
        nxt[1] += freq[9];
        nxt[1] %= MOD;
        
        std::swap(freq, nxt);
        
        for(int j = 0; j < 10; j++) {
            dp[i] += freq[j];
            dp[i] %= MOD;
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
