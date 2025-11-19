#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t A, B, N;
    std::cin >> A >> B >> N;

    int64_t x = A % B == 0 ? A / B - 1 : A / B;

    int64_t ans = 1;
    if(x > 0 && x + 1 <= N) {
        if(x + 1 < N) {
            ans += 1;
        } else {
            int64_t s = N * B * x;
            if(s % A != 0) {
                ans += 1;
            }
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
