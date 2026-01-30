#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t L, R, M;
    std::cin >> L >> R >> M;

    for(int64_t a = L; a <= R; a++) {
        int64_t n = M / a;
        int64_t m = (M + a - 1) / a;

        int64_t d = M - n * a;
        if(n > 0 && R - L >= d) {
            std::cout << a << ' ' << L + d << ' ' << L << '\n';
            return;
        }
        
        d = m * a - M;
        if(m > 0 && R - L >= d) {
            std::cout << a << ' ' << L << ' ' << L + d << '\n';
            return;
        }
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
