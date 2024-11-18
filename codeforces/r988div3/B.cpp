#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K;
    std::cin >> K;
    
    std::vector<int> A(K);
    std::vector<int> freq(K + 1, 0);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    for(int i = 0; i < K; i++) {
        int x = A[i]; 
        if((K - 2) % x == 0) {
            int y = (K - 2) / x;
            if((x == y && freq[x] > 1) || (x != y && freq[y])) {
                std::cout << x << ' ' << y << '\n';
                return;
            }
        }
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
