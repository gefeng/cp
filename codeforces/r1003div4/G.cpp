#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    std::vector<int> is_prime(N + 1, 1);
    std::vector<int64_t> dp(N + 1, 0);
    
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= N; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int64_t ans = 0;
    std::vector<int> seen(N + 1, 0);
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i + i, k = 2; j <= N; j += i, k++) {
                if(is_prime[k]) {
                    dp[i] += freq[j];
                    if(!seen[j]) {
                        ans += freq[j];
                        seen[j] = 1;
                    }
                }
            } 
        }
    }

    int64_t cnt_prime = 0;
    for(int i = 0; i < N; i++) {
        if(is_prime[A[i]]) {
            cnt_prime += 1;
            ans += dp[A[i]];
        }
    }

    int64_t x = 0;
    for(int i = 2; i <= N; i++) {
        if(freq[i] && is_prime[i]) {
            x += freq[i] * (cnt_prime - freq[i]);
        }
        if(seen[i]) {
            ans += int64_t(freq[i]) * (freq[i] - 1) / 2;
        }
    }

    ans += x / 2;

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
