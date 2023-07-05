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
    int Q;
    std::cin >> N >> Q;

    int hb = -1;
    for(int i = 62; i >= 0; i--) {
        if(N & ((int64_t)1 << i)) {
            hb = i; 
            break;
        }
    }

    int64_t x = (int64_t)1 << (hb + 1);

    for(int i = 0; i < Q; i++) {
        int64_t L;
        int64_t R;
        std::cin >> L >> R;

        L -= 1;

        int64_t res = 0;
        res += R / x -  L / x;
        res += (R + 1) / x - (L + 1) / x;
        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
