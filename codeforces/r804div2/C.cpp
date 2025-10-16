#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> pos(N, 0);
    std::vector<int64_t> fact(N + 1, 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        pos[A[i]] = i;
        fact[i + 1] = fact[i] * (i + 1) % MOD;
    }

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int> fixed(N, 0);
    int l = std::min(pos[0], pos[1]);
    int r = std::max(pos[0], pos[1]);
    fixed[l] = 1;
    fixed[r] = 1;

    int64_t ans = 1;
    int cnt = r - l - 1;
    for(int i = 2; i < N; i++) {
        int p = pos[i]; 
        if(p > l && p < r) {
            ans *= cnt;
            ans %= MOD;
            cnt -= 1;
        } else {
            if(p < l) {
                cnt += l - p - 1;
                l = p;
            } else {
                cnt += p - r - 1;
                r = p;
            }
            fixed[p] = 1;
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
