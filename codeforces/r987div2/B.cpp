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
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != i + 1) {
            if(i + 1 < N && std::abs(A[i] - A[i + 1]) == 1) {
                std::swap(A[i], A[i + 1]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(A[i] != i + 1) {
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
