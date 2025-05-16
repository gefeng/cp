#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int64_t INF = int64_t(4e18);

void run_case() {
    int N, X, Y, Z;
    std::cin >> N >> X >> Y >> Z;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<int64_t> suffix(N + 1, 0);
    for(int i = N - 1; i >= 0; i--) {
        suffix[N - i] = suffix[N - i - 1] + A[i];
    }

    int64_t ans = INF;
    int64_t prefix = 0;
    for(int i = 0; i < N; i++) {
        int64_t a = int64_t(A[i]) * i - prefix;
        int64_t b = suffix[N - 1 - i] - int64_t(A[i]) * (N - 1 - i);

        int64_t cost = 0;
        if(Z < X + Y) {
            int64_t d = std::min(a, b);
            cost = d * Z + (a - d) * X + (b - d) * Y;
        } else {
            cost = a * X + b * Y;
        }
        ans = std::min(ans, cost);

        prefix += A[i];
    }

    auto solve = [&](int64_t t) {
        int64_t res = 0;
        int64_t c = std::min(X + Y, Z);
        for(int i = 0; i < N; i++) {
            if(A[i] < t) {
                res += c * (t - A[i]);
            }
        }
        return res;
    };

    {
        int64_t cost = 0;
        int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
        int64_t rem = sum % N;    
        if(rem == 0) {
            ans = std::min(ans, solve(sum / N));
            std::cout << ans << '\n';
            return;
        }
     
        std::vector<int> a(A);
        
        int64_t fill = N - rem;
        int64_t t = (fill + sum) / N;
        cost = fill * X;
        for(int i = 0; i < N; i++) {
            if(A[i] < t) {
                int64_t d = std::min(fill, t - A[i]); 
                A[i] += d;
                fill -= d;
            }
        }
     
        ans = std::min(ans, solve(t) + cost);
        
        A = std::move(a);
        t = (sum - rem) / N;
        cost = rem * Y;
        for(int i = 0; i < N; i++) {
            if(A[i] > t) {
                int64_t d = std::min(rem, A[i] - t);
                A[i] -= d;
                rem -= d;
            }
        }
        
        ans = std::min(ans, solve(t) + cost);
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
