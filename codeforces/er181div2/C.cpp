#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t L, R;
    std::cin >> L >> R;

    auto count = [](int64_t r) {
        std::array<int, 4> a = {2, 3, 5, 7};    
        int64_t cnt = 0;
        for(int i = 0; i < 4; i++) {
            cnt += r / a[i];
        }

        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                cnt -= r / (a[i] * a[j]);
            }
        }

        for(int i = 0; i < 4; i++) {
            for(int j = i + 1; j < 4; j++) {
                for(int k = j + 1; k < 4; k++) {
                    cnt += r / (a[i] * a[j] * a[k]);
                }
            }
        }

        int p = 1;
        for(int i = 0; i < 4; i++) {
            p *= a[i];
        }
        cnt -= r / p;

        return cnt;
    };

    int64_t cnt = count(R) - count(L - 1);
    int64_t ans = R - L + 1 - cnt;

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
