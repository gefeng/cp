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

    std::vector<int> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    int64_t sum = 0;
    for(int i = 0; i < K - 1; i++) {
        ans += A[i] - 1;
        sum += A[i];
    }

    ans += sum;
    
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
