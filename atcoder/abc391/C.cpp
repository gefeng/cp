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
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> pos(N, 0);
    std::vector<int> cnt(N, 1);
    
    std::iota(pos.begin(), pos.end(), 0);

    int ans = 0;
    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int P, H;
            std::cin >> P >> H;
            P -= 1;
            H -= 1;
            
            int p = pos[P];
            if(--cnt[p] == 1) {
                ans -= 1;
            }
            if(++cnt[H] == 2) {
                ans += 1;
            }
            pos[P] = H;
        } else {
            std::cout << ans << '\n';
        }
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
