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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(A[0] > 1) {
        std::cout << 1 << '\n';
        return;
    }

    int64_t ans = 1;
    for(int i = 0, j = 0; i < K; i++) {
        while(j < N && A[j] - (j + 1) < ans) {
            j += 1;
        }

        ans += j;
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
