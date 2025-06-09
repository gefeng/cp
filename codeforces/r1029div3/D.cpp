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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t a = int64_t(N) * A.back() - A.front();
    int64_t b = int64_t(N) * N - 1;

    if(a % b != 0) {
        std::cout << "No" << '\n';
        return;
    }

    int64_t x = a / b;
    int64_t y = A.back() - x * N;
    
    if(x < 0 || y < 0) {
        std::cout << "No" << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        A[i] -= x * (i + 1);
        A[i] -= y * (N - i);
        if(A[i] != 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
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
