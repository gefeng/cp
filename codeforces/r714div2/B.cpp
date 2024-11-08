#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int t = A[0];
    for(int i = 1; i < N; i++) {
        t &= A[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] == t) {
            cnt += 1;
        }
    }

    if(cnt < 2) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = int64_t(cnt) * (cnt - 1);
    for(int i = 1; i <= N - 2; i++) {
        ans *= i;
        ans %= MOD;
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
