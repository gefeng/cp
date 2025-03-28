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

    std::array<int, 10> freq = {};
    std::array<int, 10> zero = {};
    freq[0] += 3;
    freq[1] += 1;
    freq[2] += 2;
    freq[3] += 1;
    freq[5] += 1;
    
    for(int i = 0; i < N; i++) {
        if(freq[A[i]] > 0) {
            freq[A[i]] -= 1;
        }
        if(freq == zero) {
            std::cout << i + 1 << '\n';
            return;
        }
    }

    std::cout << 0 << '\n';
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
