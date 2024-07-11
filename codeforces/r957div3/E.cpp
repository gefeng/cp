#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = (int)1e4;

void run_case() {
    int N;
    std::cin >> N;

    auto get_base = [](int x) {
        int base = 1;
        while(x) {
            base *= 10;
            x /= 10;
        }
        return base;
    };

    int base = get_base(N);
    int cnt_c = base == 10 ? 1 : (base == 100 ? 2 : 3);

    std::vector<std::pair<int, int>> ans;
    for(int a = 1; a <= MAX; a++) {
        int b = std::min(a * cnt_c - 1, std::min(MAX, a * N));
        while(b >= 1) {
            int x = N * a - b;
            int c = a * cnt_c - b;
            int64_t y = 0;
            int s = c / cnt_c;
            int r = c % cnt_c;
            bool good = true;
            for(int i = 0; i < s; i++) {
                y = y * base + N;
                if(y - x >= MAX) {
                    good = false;
                    break;
                }
            } 

            if(!good) {
                break;
            }
            
            int d = base / 10;
            while(r) {
                y = y * 10 + N / d;
                d /= 10;
                r -= 1;
            } 

            if(x == y) {
                ans.emplace_back(a, b);
            }

            b -= 1;
        }
    }

    int n = ans.size();
    std::cout << n << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
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
