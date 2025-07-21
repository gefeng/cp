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

    int M;
    std::cin >> M;
    
    std::vector<int> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    int64_t ans = 0;
    int64_t max_s = 0;
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        max_s = std::max(max_s, sum);
    }
    ans += max_s;
    
    max_s = 0;
    sum = 0;
    for(int i = 0; i < M; i++) {
        sum += B[i];
        max_s = std::max(max_s, sum);
    }
    ans += max_s;

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
