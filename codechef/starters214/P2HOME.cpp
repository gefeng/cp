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
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    auto contain = [](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        return r2 <= r1 || (l1 == l2 && r1 <= r2);
    };

    auto intersect = [](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        return l2 <= r1;
    };

    for(int i = 0; i < N - 1; i++) {
        if(contain(std::min(A[i], B[i]), std::max(A[i], B[i]), std::min(A[i + 1], B[i + 1]), std::max(A[i + 1], B[i + 1]))) {
            std::cout << "No" << '\n';
            return;
        }
        if(intersect(std::min(A[i], B[i]), std::max(A[i], B[i]), std::min(A[i + 1], B[i + 1]), std::max(A[i + 1], B[i + 1]))) {
            if(static_cast<int64_t>(A[i] - B[i]) * (A[i + 1] - B[i + 1]) < 0) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
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
