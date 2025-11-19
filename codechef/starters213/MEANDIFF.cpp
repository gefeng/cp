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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A); 

    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < N - 1; i++) {
        sum += A[i];
        int64_t avg = (sum + A.back()) / (i + 2);
        ans = std::max(ans, A.back() - avg);
        ans = std::max(ans, avg - A[0]);
    }

    sum = 0;
    for(int i = N - 1; i > 0; i--) {
        sum += A[i];
        int64_t avg = (sum + A[0]) / (N - i + 1);
        ans = std::max(ans, A.back() - avg);
        ans = std::max(ans, avg - A[0]);
    }

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
