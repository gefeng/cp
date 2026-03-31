#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int ans = 0;
    std::vector<int> vis(N, 0);
    for(int i = 0; i < N; i++) {
        int64_t l = i == 0 ? 1 : gcd(A[i - 1], A[i]);
        int64_t r = i == N - 1 ? 1 : gcd(A[i + 1], A[i]);
        int64_t x = l * r / gcd(l, r);

        if(x >= 1 && x <= B[i] && x < A[i]) {
            A[i] = x;
            vis[i] = 1;
            ans++;
        }
    }

    std::vector<int> primes = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
    
    int n = primes.size();

    std::vector<int> dp(n, -1);
    std::vector<int> ndp(n, -1);
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            continue;
        }
        
        int j = i;
        while(i + 1 < N && !vis[i + 1]) {
            i++;
        }

        dp.assign(n, -1);
        dp[0] = 0;
        for(int k = 1; k < n; k++) {
            int64_t l = j == 0 ? 1 : gcd(A[j - 1], A[j]);
            int64_t r = j == N - 1 ? 1 : gcd(A[j + 1], A[j]);
            int64_t x = A[j] * primes[k];
            if(x <= B[j] && gcd(x, j == 0 ? 1 : A[j - 1]) == l && gcd(x, j == N - 1 ? 1 : A[j + 1]) == r) {
                dp[k] = 1;
            }
        }

        for(int p = j + 1; p <= i; p++) {
            int64_t l = p == 0 ? 1 : gcd(A[p - 1], A[p]);
            ndp.assign(n, -1); 
            ndp[0] = 0;
            for(int k1 = 0; k1 < n; k1++) {
                if(dp[k1] == -1) {
                    continue;
                }
                
                if(gcd(A[p], A[p - 1] * primes[k1]) == l) {
                    ndp[0] = std::max(ndp[0], dp[k1]);
                }

                for(int k2 = 0; k2 < n; k2++) {
                    if(A[p] * primes[k2] > B[p]) {
                        break;
                    }
                    if(gcd(A[p] * primes[k2], A[p - 1] * primes[k1]) == l) {
                        ndp[k2] = std::max(ndp[k2], dp[k1] + (k2 != 0 ? 1 : 0));
                    }
                }
            }
            dp = std::move(ndp);
        }

        int64_t r = i == N - 1 ? 1 : gcd(A[i], A[i + 1]);
        int max_v = 0;
        for(int k = 0; k < n; k++) {
            if(dp[k] != -1 && gcd(primes[k] * A[i], i == N - 1 ? 1 : A[i + 1]) == r) {
                max_v = std::max(max_v, dp[k]);
            }
        }
        ans += max_v;
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
