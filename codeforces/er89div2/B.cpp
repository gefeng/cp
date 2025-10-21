#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, X;
    std::cin >> N >> X >> M;
    X -= 1;

    auto overlap = [](int x, int y, int l, int r) {
        if(x > l) {
            std::swap(x, l);
            std::swap(y, r);
        }
        return y >= l;
    };
    
    int l = -1;
    int r = -1;
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        if(l == -1) {
            if(X >= L && X <= R) {
                l = L;
                r = R;
            }
        } else {
            if(overlap(L, R, l, r)) {
                l = std::min(l, L);
                r = std::max(r, R);
            }
        }
    }

    std::cout << r - l + 1 << '\n';
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
