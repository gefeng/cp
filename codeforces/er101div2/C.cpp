#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t l = A[0];
    int64_t r = A[0];
    for(int i = 1; i < N; i++) {
        int64_t x = l - K + 1;
        int64_t y = r + K - 1;
        //y = std::min(y, static_cast<int64_t>(A[i] + K - 1));
        
        if(y < A[i]) {
            std::cout << "No" << '\n';
            return;
        }
        
        x = std::max(int64_t(A[i]), x);
        if(x > A[i] + K - 1) {
            std::cout << "No" << '\n';
            return;
        }

        y = std::min(int64_t(A[i] + K - 1), y);

        if(x > y) {
            std::cout << "No" << '\n';
            return;
        }
        
        l = x;
        r = y;
    }

    std::cout << (l == A.back() ? "Yes" : "No") << '\n';
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
