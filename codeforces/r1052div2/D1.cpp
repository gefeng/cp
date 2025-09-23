#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    int n = R - L + 1;
    std::vector<int> ans(n, 0);
    
    std::iota(ans.begin(), ans.end(), 0);

    std::vector<int> p2(30, 1);
    for(int i = 1; i < 30; i++) {
        p2[i] = p2[i - 1] * 2;
    }

    while(true) {
        if(R <= 0) {
            break;
        }
        
        // find 2^t > R
        int x = 0;
        for(int i = 0; i < 30; i++) {
            x = p2[i];
            if(p2[i] > R) {
                break;
            }
        }

        int d = x - R;
        std::ranges::reverse(ans.begin() + d - 1, ans.begin() + R + 1);
        
        R = d - 2;
    }

    int64_t sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ans[i] | i;
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
