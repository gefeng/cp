#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int64_t min_s = 0;
    int64_t max_s = 0;
    for(int i = 0; i < N; i++) {
        int64_t nxt_min = std::min(min_s - A[i], max_s - A[i]);
        nxt_min = std::min(nxt_min, std::min(B[i] - min_s, B[i] - max_s));

        int64_t nxt_max = std::max(min_s - A[i], max_s - A[i]);
        nxt_max = std::max(nxt_max, std::max(B[i] - min_s, B[i] - max_s));

        min_s = nxt_min;
        max_s = nxt_max;
    }

    std::cout << max_s << '\n';
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
