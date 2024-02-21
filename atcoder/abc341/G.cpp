#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
    }

    std::vector<double> ans(N + 1);
    std::vector<std::pair<int64_t, int64_t>> s;
    
    s.emplace_back(N, psum[N]);
    
    for(int k = N - 1; k >= 0; k--) {
        int64_t x = k;
        int64_t y = psum[k];

        while(s.size() > 1) {
            auto [x0, y0] = s.back();
            auto [x1, y1] = s[s.size() - 2];
            
            int64_t c_prod = (x0 - x) * (y1 - y) - (y0 - y) * (x1 - x);
            if(c_prod >= 0) {
                s.pop_back();
            } else {
                break;
            }
        }
        
        auto [x0, y0] = s.back();
        ans[k + 1] = std::max((double)A[k], (double)(y0 - y) / (x0 - x));

        s.emplace_back(x, y);
    }

    std::cout << std::setprecision(20);
    for(int k = 1; k <= N; k++) {
        std::cout << ans[k] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
