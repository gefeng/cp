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

    for(int i = 1; i < N - 1; i++) {
        A[i] -= A[i - 1] * 2;
        A[i + 1] -= A[i - 1];
        A[i - 1] = 0;
        if(A[i] < 0 || A[i + 1] < 0) {
            std::cout << "No" << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != 0) {
            std::cout << "No" << '\n';
            return;
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
