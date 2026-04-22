#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <random>
#include <chrono>

constexpr int MAX = static_cast<int>(1e6);

void run_case() {
    int N, R;
    std::cin >> N >> R;
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto in_circle = [](int64_t x, int64_t y, int64_t r, int64_t tx, int64_t ty) {
        return (x - tx) * (x - tx) + (y - ty) * (y - ty) <= r * r;
    };

    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    int w = 2 * R;
    int h = std::ceil((sqrt(3) * R));

    while(true) {
        int cover = 0;
        std::vector<std::pair<int, int>> ans;

        int64_t x0 = rng() % MAX;
        int64_t y0 = rng() % MAX;
        
        for(auto [px, py] : A) {
            int64_t col = (px - x0) / w;
            int64_t row = (py - y0) / h;
            bool found = false;
            for(int dx = -2; dx <= 2; dx++) {
                for(int dy = -2; dy <= 2; dy++) {
                    int64_t x = x0 + (col + dx) * w + ((row + dy) % 2) * R;
                    int64_t y = y0 + (row + dy) * h;

                    if(in_circle(x, y, R, px, py)) {
                        cover++;
                        found = true;
                        ans.emplace_back(x, y);
                        break;
                    }
                }
                if(found) {
                    break;
                }
            }
        }

        if(100 * cover >= 89 * N) {
            std::ranges::sort(ans);
            ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
            int k = ans.size();            
            std::cout << k << '\n';
            for(int i = 0; i < k; i++) {
                std::cout << ans[i].first << ' ' << ans[i].second << '\n';
            }
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
