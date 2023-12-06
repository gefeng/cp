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
    int64_t L, R;
    std::cin >> N >> L >> R;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] >= L && A[i] <= R) {
            std::cout << A[i] << '\n'; 
            continue;
        }
        
        int64_t min_v = std::min(std::abs(L - A[i]), std::abs(R - A[i]));
        if(std::abs(L - A[i]) <= min_v) {
            std::cout << L << '\n';
        } else {
            std::cout << R << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
