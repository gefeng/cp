#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    int64_t M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::map<int64_t, int64_t> m;
    for(int i = 0; i < N; i++) {
        m[A[i]] += B[i];
    }

    int64_t ans = 0;
    for(auto [k, f1] : m) {
        int64_t ub1 = std::min(f1, M / k);
        ans = std::max(ans, ub1 * k);
 
        if(m.find(k + 1) != m.end()) {
            int64_t f2 = m[k + 1];
            int64_t ub2 = std::min(m[k + 1], M / (k + 1));

            ans = std::max(ans, ub1 * k + std::min(ub2, (M - ub1 * k) / (k + 1)) * (k + 1));
            ans = std::max(ans, ub2 * (k + 1) + std::min(ub1, (M - ub2 * (k + 1)) / k) * k);

            int64_t rem = M % k;
            if(ub2 - rem >= 0 && M - rem - rem * k >= 0) {
                int64_t t = std::min((M - rem - rem * k) / (k * k + k), (ub2 - rem) / k);
                int64_t b = t * k + rem;
                int64_t a = (M - b * (k + 1)) / k;
                if(t >= 0 && a >= 0 && a <= ub1) {
                    ans = std::max(ans, a * k + b * (k + 1));
                }
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
