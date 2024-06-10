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
 
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
 
    std::vector<int64_t> psum(N + 1, 0);
    std::vector<int64_t> p2(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
        p2[i] = p2[i - 1] * 2 % MOD;
    }

 
    int64_t max_v = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i]; 
        max_v = std::max(max_v, std::abs(sum) + psum[N] - psum[i + 1]);
    }
 
    sum = 0;
    int64_t ans = 0;
    int64_t x = 1;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(std::abs(sum) + psum[N] - psum[i + 1] == max_v) {
            if(sum < 0) {
                ans += x * p2[N - i - 1] % MOD;
            } else {
                ans = p2[N];
                break;
            }
            ans %= MOD;
        } else {
            if(sum >= 0) {
                x *= 2;
                x %= MOD;
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
