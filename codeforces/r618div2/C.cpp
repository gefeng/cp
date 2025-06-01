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

    int p = -1;
    for(int i = 29; i >= 0; i--) {
        int cnt = 0;
        p = -1;
        for(int j = 0; j < N; j++) {
            if(A[j] & (1 << i)) {
                p = j;
                cnt += 1;
            }
        }

        if(cnt == 1) {
            break; 
        }
    }

    if(p == -1) {
        for(int i = 0; i < N; i++) {
            std::cout << A[i] << " \n"[i == N - 1];
        }
    } else {
        std::cout << A[p] << " \n"[N == 1];
        for(int i = 0; i < N; i++) {
            if(i != p) {
                std::cout << A[i] << " \n"[i == N - 1];
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
