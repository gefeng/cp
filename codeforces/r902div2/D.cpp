#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    for(int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    std::vector<int> save_max(N + 1, -1);
    for(int i = N; i > 0; i--) {
        save_max[i] = A[i];
        for(int j = i + i; j <= N; j += i) {
            save_max[i] = std::max(save_max[i], save_max[j]);
        }
    }

    std::sort(save_max.begin(), save_max.end());

    int64_t ans = 0;
    for(int i = 1; i <= N; ) {
        int j = i;
        while(i <= N && save_max[i] == save_max[j]) {
            i += 1;
        }

        for(int k = j; k < i; k++) {
            ans += p2[k - 1] * save_max[j] % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
