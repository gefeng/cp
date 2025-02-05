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

    if(N == 1 || N == 2) {
        std::cout << 0 << '\n';
        return;
    }

    std::sort(A.begin(), A.end());
    
    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 2; i < N; i++) {
        ans += int64_t(i - 1) * A[i] - sum;
        sum += A[i - 1];
    }

    std::cout << -ans << '\n';
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
