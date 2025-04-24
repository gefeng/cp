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

    int size = N * K;
    std::vector<int> A(size);
    for(int i = 0; i < size; i++) {
        std::cin >> A[i];
    } 

    int64_t ans = 0;
    for(int i = ((N + 1) / 2 - 1) * K; i < size; i += N / 2 + 1) {
        ans += A[i];
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
