#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K, H;
    std::cin >> N >> K >> H;

    int64_t ans = 0;
    if(N >= H) {
        ans += (int64_t)(N - H + 1) * N;
    }
    
    for(int i = 2; i <= std::min(H - 1, N); i++) {
        if((int64_t)i * K - H < 0) {
            continue;
        }

        int64_t ub = ((int64_t)i * K - H) / (K - 1);
        if(ub >= 1) {
            ans += ub;
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
