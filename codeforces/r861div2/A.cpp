#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    int d = R - L;
    
    int ans = 0;
    int max_v = -1;
    for(int i = 0; i <= std::min(100, d); i++) {
        int x = L + i;
        int min_d = 10;
        int max_d = -1;
        while(x) {
            int y = x % 10;
            min_d = std::min(min_d, y);
            max_d = std::max(max_d, y);
            x /= 10;
        }

        if(max_d - min_d > max_v) {
            ans = L + i;
            max_v = max_d - min_d;
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
