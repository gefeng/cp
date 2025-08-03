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

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int a = std::ranges::count(A, 1);
    int b = std::ranges::count(B, 1);
    
    if(a != b) {
        std::cout << "No" << '\n';
        return;
    }

    if(A == B || a >= 2) {
        std::cout << "Yes" << '\n';
        return;
    }

    if(A[0] == 1 || A.back() == 1 || B[0] == 1 || B.back() == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
