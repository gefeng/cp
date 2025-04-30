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

    std::vector<int> A(N);
    std::vector<int> cnt(N, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
        cnt[A[i]] += 1;
    }

    for(int i = 0; i < N; i++) {
        if(cnt[i] > 2) {
            std::cout << 0 << '\n';
            return;
        }
        if(cnt[i] == 2 && cnt[N - 1 - i]) {
            std::cout << 0 << '\n';
            return;
        }
        if(cnt[i] == 1 && cnt[N - 1 - i] != 1) {
            std::cout << 0 << '\n';
            return;
        }
    } 

    if(N % 2 == 1 && cnt[N / 2] != 1) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = 1;
    for(int i = 0; i < N / 2; i++) {
        ans *= 2;
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
