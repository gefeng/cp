#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, K;
    std::cin >> N >> K;

    int ans = 0;
    while(N) {
        if(K == 1) {
            ans += N;
            break;
        }
        int64_t x = 1;
        while(x <= N) {
            x *= K;
        }
        x /= K;
        if(x == 1) {
            ans += N;
            break;
        }
        N -= x;
        ans += 1;
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
