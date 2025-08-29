#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int64_t X;
    std::cin >> X;

    int64_t x = std::abs(4 * X - 1);

    auto solve = [&](int64_t a, int64_t b) {
        if((a - b - 2) % 4 == 0) {
            return (a - b - 2) / 4;
        }
        return INF;
    };

    std::vector<int64_t> ans;
    for(int64_t f = 1; f * f <= x; f++) {
        if(x % f == 0) {
            int64_t a = f;
            int64_t b = x / f;
            
            if(4 * X - 1 < 0) {
                int64_t res = solve(-a, b);
                if(res != INF) {
                    ans.push_back(res);
                }
                res = solve(a, -b);
                if(res != INF) {
                    ans.push_back(res);
                }
                res = solve(-b, a);
                if(res != INF) {
                    ans.push_back(res);
                }
                res = solve(b, -a);
                if(res != INF) {
                    ans.push_back(res);
                }
            } else {
                int64_t res = solve(a, b);
                if(res != INF) {
                    ans.push_back(res);
                }

                res = solve(b, a);
                if(res != INF) {
                    ans.push_back(res);
                }
            }
        } 
    }
    
    std::ranges::sort(ans);
    ans.erase(std::unique(ans.begin(), ans.end()), ans.end());

    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
