#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int max_v = *std::max_element(A.begin(), A.end());
    for(int i = 0; i < M; i++) {
        char T;
        std::cin >> T;
    
        int L, R;
        std::cin >> L >> R;

        if(T == '+') {
            if(max_v >= L && max_v <= R) {
                max_v += 1;
            } 
        } else {
            if(max_v >= L && max_v <= R) {
                max_v -= 1;
            }
        }

        std::cout << max_v << " \n"[i == M - 1];
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
