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
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    //std::ranges::sort(A);
    
    int64_t g = std::abs(A[1] - A[0]);
    for(int i = 2; i < N; i++) {
        g = gcd(g, std::abs(A[i] - A[i - 1]));
    }

    for(int i = 0; i < N; i++) {
        if((K - A[i]) % g == 0) {
            std::cout << "YES" << '\n';
            return;
        }
    }
    
    std::cout << "NO" << '\n';
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
