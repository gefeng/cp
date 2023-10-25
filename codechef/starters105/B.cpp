#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, P, Q;
    std::cin >> N >> P >> Q;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::sort(A.begin(), A.end());
    
    int64_t max_v = A.back();
    int64_t min_v = A.front();
    int l = 1;
    int r = N - 2;
    while(l <= r && (A[l] != 0 || A[r] != 0) && (P || Q)) {
        if(P > Q) {
            if(A[r] > 0) {
                max_v += A[r--]; 
            } else {
                min_v += A[l++];
            }
            P -= 1;
        } else {
            if(A[r] > 0) {
                min_v -= A[r--];
            } else {
                max_v -= A[l++];
            }
            Q -= 1;
        }
    }

    std::cout << max_v - min_v << '\n';
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
