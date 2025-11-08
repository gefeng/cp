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

    int eve = -1;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            if(eve != -1) {
                std::cout << eve << ' ' << A[i] << '\n';
                return;
            }
            eve = A[i];
        }
    }

    for(int i = 1; i < N; i++) {
        if((A[i] % A[i - 1]) % 2 == 0) {
            std::cout << A[i - 1] << ' ' << A[i] << '\n';
            return;
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if((A[j] % A[i]) % 2 == 0) {
                std::cout << A[i] << ' ' << A[j] << '\n';
                return;
            }
        }
    }

    std::cout << -1 << '\n';
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
