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

    std::map<int, int> m;
    for(int x : A) {
        m[x] += 1;
    }

    int64_t ans = 0;
    for(auto [x, f1] : m) {
        int64_t cnt1 = std::min(int64_t(f1), M / x);
        ans = std::max(ans, cnt1 * x);

        if(m.find(x + 1) != m.end()) {
            int64_t y = x + 1;
            int64_t f2 = m[y];
            
            int64_t cnt2 = std::min(f2, M / y); 

            for(int64_t a = 0; a <= cnt1; a++) {
                ans = std::max(ans, a * x + std::min(cnt2, (M - a * x) / y) * y);
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
