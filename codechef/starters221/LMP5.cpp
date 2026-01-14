#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int64_t>(2e9) + 10;

void run_case() {
    int L, W, R, G, B;
    std::cin >> L >> W >> R >> G >> B;

    std::array<int, 3> a = {R, G, B};
    std::array<int, 4> b = {L, L, W, W};
    std::array<int, 4> c = {0, 1, 2, 3};
    
    std::ranges::sort(a, std::greater<int>());

    int ans = INF;
    do {
        std::array<int, 3> d = {0, 1, 2};
        do {
            std::array<int, 3> color(a);
            int cost = 0;
            for(int i = 0, j = 0; i < 4; i++) {
                int l = b[c[i]];  
                while(l) {
                    int x = std::min(l, color[d[j]]);
                    color[d[j]] -= x;
                    l -= x;
                    cost += 1;
                    if(color[d[j]] == 0) {
                        j += 1;
                    }
                }
            }
            ans = std::min(ans, cost);
        } while(std::next_permutation(d.begin(), d.end()));

    } while(std::next_permutation(c.begin(), c.end()));

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
