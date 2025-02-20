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

    int pre_odd = 0;
    int pre_eve = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] % 2 == 0) {
            if(A[i] < pre_eve) {
                std::cout << "No" << '\n';
                return;
            }
            pre_eve = A[i];
        } else {
            if(A[i] < pre_odd) {
                std::cout << "No" << '\n';
                return;
            }
            pre_odd = A[i];
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
