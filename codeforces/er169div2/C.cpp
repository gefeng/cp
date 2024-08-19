#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int64_t sa = 0;
    int64_t sb = 0;
    for(int i = N - 1; i >= 0; i -= 2) {
        sa += A[i];
        
        if(i - 1 >= 0) {
            int d = std::min(K, A[i] - A[i - 1]);
            K -= d;
            sb += A[i - 1] + d;
        }
    }

    std::cout << sa - sb << '\n';
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
