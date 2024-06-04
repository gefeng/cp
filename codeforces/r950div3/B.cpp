#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, F, K;
    std::cin >> N >> F >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    int fav = A[F - 1];
    
    std::sort(A.begin(), A.end(), std::greater<int>());
    
    if(fav == A[K - 1]) {
        std::cout << (K == N || A[K] < A[K - 1] ? "Yes" : "Maybe" ) << '\n';
    } else if(fav > A[K - 1]) {
        std::cout << "Yes" << '\n';
    } else {
        std::cout << "No" << '\n';
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
