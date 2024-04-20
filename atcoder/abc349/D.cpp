#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;

    std::vector<int64_t> p2(61, 1);
    for(int i = 1; i <= 60; i++) {
        p2[i] = p2[i - 1] * 2;
    }

    int64_t cur = L;
    std::vector<std::pair<int64_t, int64_t>> ans;
    while(cur != R) {
        for(int i = 60; i >= 0; i--) {
            if(cur % p2[i] == 0) {
                int64_t x = cur / p2[i];
                if(R / p2[i] >= x + 1) {
                    int64_t nxt = p2[i] * (x + 1);
                    ans.emplace_back(cur, nxt);
                    cur = nxt;
                    break;
                }
            }
        } 
    }

    std::cout << ans.size() << '\n';
    for(auto [l, r] : ans) {
        std::cout << l << ' ' << r << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
