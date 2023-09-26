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

    if(N == 1) {
        std::cout << std::max(0, A[0]) << '\n';
        return;
    }
    
    int64_t sum = 0;
    for(int i = 2; i < N; i++) {
        sum += std::max(0, A[i]); 
    }

    int64_t ans = std::max(sum + std::max(0, A[0]), sum + A[0] + std::max(0, A[1]));

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
