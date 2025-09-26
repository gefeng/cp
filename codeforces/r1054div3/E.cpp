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
    int N, K, L, R;
    std::cin >> N >> K >> L >> R;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto solve = [&](int k) {
        std::map<int, int> m;
        int64_t res = 0;
        for(int i = 0, j = 0; i < N; i++) {
            m[A[i]] += 1;
            
            while(m.size() > k) {
                if(--m[A[j]] == 0) {
                    m.erase(A[j]);
                }
                j += 1;
            }

            int l = std::max(i + 1 - R, j);
            int r = std::min(i + 1 - L, i);
            if(l <= r && l >= 0) {
                res += r - l + 1;
            }
        }
        return res;
    };

    int64_t ans = solve(K) - solve(K - 1);
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
