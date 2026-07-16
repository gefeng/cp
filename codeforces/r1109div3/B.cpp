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

    if(N == 1) {
        std::cout << "YES" << '\n';
        return;
    }

    for(int i = 0, j = 1; i < N - 1; i++, j++) {
        if(A[i] < j) {
            std::cout << "NO" << '\n';
            return;
        }
        A[i + 1] += A[i] - j;
        A[i] = j;
    }

    std::cout << (A[N - 1] > A[N - 2] ? "YES" : "NO") << '\n';
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
