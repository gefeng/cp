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

    std::sort(A.begin(), A.end(), std::greater<int>());

    int64_t sum_r = 0;
    int64_t sum_b = A[N - 1];
    for(int l = 0, r = N - 2; l < r; l += 1, r -= 1) {
        sum_r += A[l];
        sum_b += A[r];
        if(sum_r > sum_b) {
            std::cout << "YES" << '\n';
            return;
        }
    } 
    
    std::cout << "NO" << '\n';
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
