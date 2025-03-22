#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(M);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());
    std::sort(B.begin(), B.end(), std::greater<int>());

    int64_t ans = 0;
    int64_t sum_a = 0;
    int64_t sum_b = 0;
    for(int i = 0, j = 0; i <= M; i++) {
        if(i) {
            sum_b += B[i - 1];
        }
        
        while(j < N && (A[j] >= 0 || j < i)) {
            sum_a += A[j++]; 
        }

        if(j >= i) {
            ans = std::max(ans, sum_a + sum_b);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
