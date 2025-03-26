#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    int64_t sum = std::accumulate(A.begin(), A.end(), int64_t(0));
    
    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int X, Y;
        std::cin >> X >> Y;
    
        int64_t res = 0;
        auto it = std::lower_bound(A.begin(), A.end(), X);
        
        if(it != A.end()) {
            res = std::max(int64_t(0), Y - (sum - *it));

            if(it != A.begin()) {
                it--;
                res = std::min(res, (X - *it) + std::max(int64_t(0), Y - (sum - *it)));
            }
        } else {
            it--;
            res = (X - *it) + std::max(int64_t(0), Y - (sum - *it));
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
