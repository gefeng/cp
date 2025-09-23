#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

void run_case() {
    int L, R;
    std::cin >> L >> R;
    
    int offset = L;
    int n = R - L + 1;
    std::vector<int> ans(n, 0);

    std::iota(ans.begin(), ans.end(), L);

    std::vector<int> p2(31, 1);
    for(int i = 1; i <= 30; i++) {
        p2[i] = p2[i - 1] * 2;
    }

    int prefix = 0;
    while(true) {
        if(R <= 0 || L >= R) {
            break;
        }
        
        int x = 0;
        for(int i = 0; i <= 30; i++) {
            x = p2[i];
            if(x > R) {
                break;
            }
        }

        int d = x - R;
        if(L <= d - 1) {
            std::ranges::reverse(ans.begin() + (d | prefix) - 1 - offset, ans.begin() + (R | prefix) + 1 - offset);
            R = d - 2;
        } else {
            int r = x - L - 1;
            if(r >= L) {
                std::ranges::reverse(ans.begin() + (L | prefix) - offset, ans.begin() + (r | prefix) + 1 - offset);
                L = r + 1;
            } else {
                prefix |= (x >> 1);
                L ^= (x >> 1);
                R ^= (x >> 1);
            }
        }
    }

    int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ans[i] | (i + offset);
    }

    std::cout << sum << '\n';
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
