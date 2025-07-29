#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    int n = N << 1;
    std::vector<int64_t> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    for(int i = 0; i < n; i += 2) {
        if(A[i] != A[i + 1] || (i && A[i] == A[i - 1]) || A[i] % 2 != 0) {
            std::cout << "NO" << '\n';
            return;
        } 
    }

    if(A.back() % n != 0) {
        std::cout << "NO" << '\n';
        return;
    }

    int64_t x = A.back() / n;
    int64_t sum = x * 2;
    for(int i = n - 3; i >= 0; i -= 2) {
        if(A[i] - sum <= 0 || (A[i] - sum) % (i + 1) != 0) {
            std::cout << "NO" << '\n';
            return;
        }
        sum += (A[i] - sum) / (i + 1) * 2;
    }

    std::cout << "YES" << '\n';
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
