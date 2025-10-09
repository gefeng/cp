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

    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i + 1]) {
            sum += A[i] - A[i + 1];
        } 
    }

    int64_t x = A[0] - sum;
    ans = A.back() - x + std::abs(x) + sum;
    
    sum = 0;
    for(int i = N - 1; i > 0; i--) {
        if(A[i] > A[i - 1]) {
            sum += A[i] - A[i - 1];
        }
    }

    x = A.back() - sum;
    ans = std::min(ans, A[0] - x + std::abs(x) + sum);

    std::cout << ans << '\n';
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
