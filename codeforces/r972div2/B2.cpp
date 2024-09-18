#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    for(int i = 0; i < Q; i++) {
        int P;
        std::cin >> P;

        int res = 0;

        auto it = std::upper_bound(A.begin(), A.end(), P);
        if(it == A.end()) {
            it = std::prev(it);
            res = N - *it;
        } else {
            if(it == A.begin()) {
                res = *it - 1;
            } else {
                int l = 0;
                int r = *it;
                int m = 0;
                it = std::prev(it);
                l = *it;
                m = (l + r) / 2;
                
                res = std::min(m - l, r - m);
            }
        }

        std::cout << res << '\n';
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
