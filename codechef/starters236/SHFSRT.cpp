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

    int pre = -2;
    for(int i = 0; i < N - 1; i++) {
        if(A[i] > A[i + 1]) {
            if(pre == i - 1) {
                std::cout << "No" << '\n';
                return;
            }
            
            int64_t d = (A[i] - A[i + 1] + 1) / 2;
            A[i] -= d;
            A[i + 1] += d;
            if(i && A[i] < A[i - 1]) {
                std::cout << "No" << '\n'; 
                return;
            }
            pre = i;
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
