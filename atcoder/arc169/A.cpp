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
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i]; 
    }

    std::vector<int> lv(N, 0);
    for(int i = 1; i < N; i++) {
        std::cin >> B[i];
        B[i] -= 1;
        lv[i] = lv[B[i]] + 1;
    }

    std::vector<int64_t> sum(N, 0);
    for(int i = 0; i < N; i++) {
        sum[lv[i]] += A[i];
    }

    for(int i = N - 1; i >= 0; i--) {
        if(sum[i] > 0) {
            std::cout << "+" << '\n';
            return;
        }
        if(sum[i] < 0) {
            std::cout << "-" << '\n';
            return;
        }
    }

    std::cout << 0 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
