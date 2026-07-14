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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int64_t ans = 0;
    int distinct = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i++;
        }
        distinct++;
    }
    
    ans = p2[N - distinct];

    if(A[0] == -1) {
        for(int i = 0; i < N; ) {
            int j = i;
            while(i < N && A[i] == A[j]) {
                i++;
            }
            if(j && A[j] - 1 == A[j - 1]) {
                ans += p2[N - distinct];
                ans %= MOD;
            }
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
