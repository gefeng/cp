#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::pair<int, int>> A;
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;
        for(int j = 0; j < K; j++) {
            int X;
            std::cin >> X;
            A.emplace_back(X, i);
        }
    }

    std::sort(A.begin(), A.end());

    int n = A.size();
    std::vector<int> freq(N, 0);
    std::vector<int> greater(n, 0);
    for(int i = n - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && A[i].first == A[j].first) {
            i -= 1;
        }

        for(int k = i + 1; k <= j; k++) {
            greater[k] = n - 1 - j - freq[A[k].second];
        }
    
        for(int k = i + 1; k <= j; k++) {
            freq[A[k].second] += 1;
        }
    }

    std::vector<int64_t> save_sum(N, 0);
    int64_t sum = 0;
    int64_t ans = 0;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && A[i].first == A[j].first) {
            i += 1;
        }

        std::vector<int64_t> save_p;
        for(int k = j; k < i; k++) {
            int64_t p = q_pow(n, MOD - 2);  
            p = (p + sum) % MOD;
            p = (p - save_sum[A[k].second] + MOD) % MOD;
            
            ans += p * A[k].first % MOD;
            ans %= MOD;

            save_p.push_back(p);
        }


        for(int k = j; k < i; k++) {
            int64_t t = save_p[k - j] * q_pow(greater[k], MOD - 2) % MOD;
            save_sum[A[k].second] += t;
            save_sum[A[k].second] %= MOD;
            
            sum += t;
            sum %= MOD;
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
