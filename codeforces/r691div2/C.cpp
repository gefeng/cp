#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

int64_t gcd(int64_t a, int64_t b) {
    if(a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(M);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }
    
    std::ranges::sort(A); 
    
    A.erase(std::unique(A.begin(), A.end()), A.end());

    N = A.size();
    if(N == 1) {
        for(int i = 0; i < M; i++) {
            std::cout << A[0] + B[i] << " \n"[i == M - 1];
        }
        return;
    }

    int64_t g = A[1] - A[0];
    for(int i = 2; i < N; i++) {
        g = gcd(g, A[i] - A[0]);
    }

    for(int i = 0; i < M; i++) {
        std::cout << gcd(A[0] + B[i], g) << " \n"[i == M - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
