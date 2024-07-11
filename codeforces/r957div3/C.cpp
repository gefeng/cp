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
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    
    std::iota(A.begin(), A.end(), 1);
    
    std::reverse(A.begin(), A.end());
    
    if(M <= K) {
        std::reverse(A.begin() + (N - M), A.end());
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
    }
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
