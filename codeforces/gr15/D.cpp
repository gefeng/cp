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

    for(int i = 1; i < (1 << N); i++) {
        for(int j = 0; j < (1 << N); j++) {
            if((i & j) == 0) {
                int sum1 = 0;
                int sum2 = 0;
                for(int k = 0; k < N; k++) {
                    if(i & (1 << k)) {
                        sum1 += A[k];
                    }
                    if(j & (1 << k)) {
                        sum2 += A[k];
                    }
                }

                if(sum1 == sum2) {
                    std::cout << "Yes" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "No" << '\n';
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
