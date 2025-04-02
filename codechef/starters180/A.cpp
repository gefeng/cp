#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

void run_case() {
    int N;
    std::cin >> N;

    int64_t p_2 = 1; 
    int64_t min_v = 0;
    int64_t max_v = 0;
    int64_t now = 0;
    int64_t ans = 0;
    for(int i = 0, j = 0; i < N; i += 2, j++) {
        if(j % 2 == 0) {
            for(int k = 0; k < 2; k++) {
                if(i + k < N) {
                    now += p_2;
                    now %= MOD;
                    p_2 *= 2;
                    p_2 %= MOD;
                    max_v = now;
                }
            }
        } else {
            for(int k = 0; k < 2; k++) {
                if(i + k < N) {
                    now -= p_2;
                    now += MOD;
                    now %= MOD;
                    p_2 *= 2;
                    p_2 %= MOD;
                    min_v = now;
                }
            }
        }
    }

    ans = (max_v - min_v + MOD) % MOD;

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
