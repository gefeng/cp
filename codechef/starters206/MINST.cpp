#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t INF = static_cast<int64_t>(4e18);

std::vector<int64_t> p2(60, 1);

void run_case() {
    int64_t N, D;
    std::cin >> N >> D;

    int64_t ans = INF;
    for(int i = 0; i < 60; i++) {
        if(N < p2[i]) {
            break;
        }

        int64_t t = N - p2[i];
        if(t % D != 0) {
            continue; 
        }
        
        int64_t x = t / D;
        
        int64_t cnt = i;
        for(int j = i; j >= 0; j--) {
            int64_t y = x / p2[j];
            cnt += y;
            x -= y * p2[j];
        }
        ans = std::min(ans, cnt);
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; i < 60; i++) {
        p2[i] = p2[i - 1] * 2;
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
