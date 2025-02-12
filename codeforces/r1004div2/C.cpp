#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = 1e10;

void run_case() {
    int N;
    std::cin >> N;

    auto check = [](int64_t x) {
        while(x) {
            if(x % 10 == 7) {
                return true;
            }
            x /= 10;
        }
        return false;
    };

    if(check(N)) {
        std::cout << 0 << '\n';
        return;
    }

    int ans = 20;
    for(int64_t x = 9; x <= MAX; x = x * 10 + 9) {
        int64_t y = N;
        int cnt = 0;
        while(!check(y)) {
            y += x;
            cnt += 1;
        }
        ans = std::min(ans, cnt);
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
