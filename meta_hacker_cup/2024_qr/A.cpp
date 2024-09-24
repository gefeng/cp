#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    bool ok = true;
    if(N == 1) {
        ok = A[0] <= K;
    } else {
        ok = A[0] * 2 * (N - 2) + A[0] <= K;
    }

    std::cout << "Case #" << T << ": " << (ok ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
