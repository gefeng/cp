#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N, 0);

    std::iota(A.begin(), A.end(), 0);

    if(N % 2 == 0) {
        for(int i = 0; i < N; i += 2) {
            std::swap(A[i], A[i + 1]);
        }
    } else {
        for(int i = 0; i < N - 3; i += 2) {
            std::swap(A[i], A[i + 1]);
        }
        
        A[N - 3] = N - 1;
        A[N - 2] = N - 3;
        A[N - 1] = N - 2;
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] + 1 << " \n"[i == N - 1];
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
