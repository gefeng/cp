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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    bool inc = true;
    int64_t max_gap = 0;
    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            inc = false;
            max_gap = std::max(max_gap, A[i - 1] - A[i]);
        }
    }

    if(inc) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
            A[i] += max_gap;
        }
    }

    for(int i = 1; i < N; i++) {
        if(A[i] < A[i - 1]) {
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
