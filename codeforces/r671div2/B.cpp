#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N;
    std::cin >> N;

    int64_t x = 2;
    int64_t ans = 0;
    int64_t used = 0;
    while(true) {
        int64_t need = x * (x - 1) / 2;
        if(need + used > N) {
            break;
        }
        used += need;
        ans += 1;
        x <<= 1;
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
