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
        if(A[i] == i + 1) {
            continue;
        }
        for(int j = i + 1; j < N; j++) {
            if(A[j] == i + 1) {
                std::reverse(A.begin() + i, A.begin() + j + 1);
                for(int k = 0; k < N; k++) {
                    std::cout << A[k] << " \n"[k == N - 1];
                }
                return;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " \n"[i == N - 1];
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
