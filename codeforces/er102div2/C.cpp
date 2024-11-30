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
    for(int i = 0; i < K; i++) {
        A[i] = i + 1;
    }
    
    for(int i = K, j = K - 1; i < N; i++, j--) {
        A[i] = j;
    }

    int last = K - (N - K);
    std::vector<int> b(A);
    for(int i = last - 1, j = K; i < K; i++, j--) {
        b[i] = j;
    }

    for(int i = K, j = last; i < N; i++, j++) {
        b[i] = j;
    }

    for(int i = 0; i < K; i++) {
        std::cout << b[i] << " \n"[i == K - 1];
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
