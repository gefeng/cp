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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::sort(A.begin(), A.end());

    int64_t p = 0;
    for(int i = 1; i < N; i++) {
        int64_t np = std::max(A[i] + p + 1, p + A[i - 1] + 1);

        if(np < M) {
            p = np;
        } else {
            std::cout << "NO" << '\n';
            return;
        }
    }

    int64_t d = M - 1 - p;
    
    std::cout << (d >= std::max(A[0], A.back()) ? "YES" : "NO") << '\n';
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
