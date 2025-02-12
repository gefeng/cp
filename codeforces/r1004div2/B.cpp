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
    std::vector<int> freq(N + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        freq[A[i]] += 1;
    }

    for(int i = 1; i <= N; i++) {
        if(freq[i] == 0) {
            continue;
        }
        
        if(freq[i] == 1) {
            std::cout << "No" << '\n';
            return;
        }

        if(i < N) {
            freq[i + 1] += freq[i] - 2;
        }
    }

    std::cout << (freq.back() % 2 == 0 ? "Yes" : "No") << '\n';
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
