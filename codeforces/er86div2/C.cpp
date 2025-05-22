#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int64_t A, B, Q;
    std::cin >> A >> B >> Q;

    if(A > B) {
        std::swap(A, B);
    }

    int64_t g = A * B / gcd(A, B);
    std::vector<int64_t> psum(g + 1, 0);
    
    for(int i = 0; i < g; i++) {
        psum[i + 1] = psum[i] + ((i % A) % B == (i % B) % A ? 1 : 0);
    }

    for(int i = 0; i < Q; i++) {
        int64_t L, R;
        std::cin >> L >> R;

        int64_t x = psum[g];

        int64_t cnt = R / g * x + psum[R % g + 1] - ((L - 1) / g * x + psum[(L - 1) % g + 1]);

        std::cout << (R - L + 1) - cnt << " \n"[i == Q - 1];
    }
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
