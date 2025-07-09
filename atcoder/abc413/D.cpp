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

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    bool ok = true;
    for(int i = 2; i < N; i++) {
        if(A[1] * A[i - 1] != A[i] * A[0]) {
            ok = false;
            break;
        }
    }

    if(ok) {
        std::cout << "Yes" << '\n';
        return;
    }

    bool unique = true;
    for(int i = 0; i < N; i++) {
        if(std::abs(A[i]) != std::abs(A[0])) {
            unique = false;
            break;
        } 
    }

    if(unique) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] < 0) {
                cnt += 1;
            }
        }
        if((N % 2 == 0 && cnt == N / 2) || (N % 2 == 1 && (cnt = N / 2 || cnt == (N + 1) / 2))) {
            std::cout << "Yes" << '\n';
        } else {
            std::cout << "No" << '\n';
        }
        return;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return std::abs(x) < std::abs(y);
            });

    ok = true;
    for(int i = 2; i < N; i++) {
        if(A[1] * A[i - 1] != A[i] * A[0]) {
            ok = false;
            break;
        }
    }

    if(ok) {
        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
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
