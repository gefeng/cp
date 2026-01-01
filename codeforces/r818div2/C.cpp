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

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        A.push_back(A[i]);
        B.push_back(B[i]);
    }

    for(int i = 0; i < N * 2 - 1; i++) {
        if(A[i] == B[i]) {
            continue;
        }

        if(B[i] - B[i + 1] > 1) {
            std::cout << "NO" << '\n';
            return;
        }
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
