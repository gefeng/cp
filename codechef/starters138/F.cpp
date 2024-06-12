#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> freq(N + 1, 0);
    for(int x : A) {
        freq[x] += 1;
    }

    int64_t sum = 0;
    for(int i = 1; i <= N; i++) {
        sum += (int64_t)(1 + freq[i]) * freq[i] / 2;
    }

    for(int i = 0; i < Q; i++) {
        int P, X;
        std::cin >> P >> X;
        P -= 1;

        int old = A[P];
        sum -= (int64_t)(1 + freq[old]) * freq[old] / 2;
        freq[old] -= 1;
        sum += (int64_t)(1 + freq[old]) * freq[old] / 2;
        
        A[P] = X;
        sum -= (int64_t)(1 + freq[X]) * freq[X] / 2;
        freq[X] += 1;
        sum += (int64_t)(1 + freq[X]) * freq[X] / 2;

        std::cout << sum << '\n';
    } 
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
