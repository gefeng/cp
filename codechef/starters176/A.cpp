#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, C;
    std::cin >> N >> C;
    
    std::string S;
    std::cin >> S;

    std::array<int, 5> freq = {};
    for(int i = 0; i < N; i++) {
        freq[S[i] - 'A'] += 1; 
    }

    int64_t ans = INF;
    for(int i = 0; i < (1 << 5); i++) {
        int64_t cost = 0;
        int64_t x = 0;
        for(int j = 0; j < 5; j++) {
            if(i & (1 << j)) {
                cost += C; 
            } else {
                x += freq[j]; 
            }
        }

        cost += (1 + x) * x / 2;
        ans = std::min(ans, cost);
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
