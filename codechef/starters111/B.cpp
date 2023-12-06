#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::array<int, 26> cnt = {};
    for(int i = 0; i < N; i++) {
        cnt[S[i] - 'a'] += 1;
    }

    int64_t ans = 1;
    for(int i = 0; i < 26; i++) {
        ans *= cnt[i] + 1;
        ans %= MOD;
    }

    std::cout << (ans - 1 + MOD) % MOD << '\n';
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
