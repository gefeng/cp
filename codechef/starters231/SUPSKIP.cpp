#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    if(M < N) {
        std::cout << M << ' ' << M + 1 << '\n';
        return;
    }

    if(M == N) {
        std::cout << M - 1 << ' ' << M << '\n';
        return;
    }
    
    std::vector<int64_t> a(31, 0);
    a[1] = 3;
    for(int i = 2; i <= 30; i++) {
        a[i] = a[i - 1] * 2 + 1;
    }

    for(int64_t c : a) {
        if(c == 0) {
            continue;
        }
        for(int64_t x = 1; x <= N; x++) {
            if(((c - 1) * x + M) % c == 0) {
                int64_t y = ((c - 1) * x + M) / c;
                if(y > x && y >= 1 && y <= N) {
                    std::cout << x << ' ' << y << '\n';
                    return;
                }
            }
        }
    }

    std::cout << -1 << '\n';
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
