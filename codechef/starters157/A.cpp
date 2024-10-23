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
    
    std::vector<int> A(N + 1);
    for(int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end() - 1);
    
    int64_t sum = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] > A.back() && A[i] <= A.back() * 2) {
            std::swap(A[i], A.back());
        }
        sum += A[i];
    }

    std::cout << sum << '\n';
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
