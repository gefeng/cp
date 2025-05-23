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
    
    std::vector<int64_t> A(N);
    std::vector<int> freq(60, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int64_t x : A) {
        int i = 0;
        while(x) {
            int d = x % K;
            freq[i++] += d;
            x /= K;
        }
    } 

    for(int i = 0; i < 60; i++) {
        if(freq[i] > 1) {
            std::cout << "NO" << '\n';
            return;
        }
    }

    std::cout << "YES" << '\n';
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
