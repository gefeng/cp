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
    
    std::array<int, 30> freq = {};
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 30; j++) {
            if(A[i] & (1 << j)) {
                freq[j] += 1;
            }
        }
    }

    int b = -1;
    for(int i = 29; i >= 0; i--) {
        if(freq[i] % 2 == 1) {
            b = i; 
            break;
        }
    }

    if(b == -1) {
        std::cout << "DRAW" << '\n';
        return;
    }

    if(freq[b] == 1) {
        std::cout << "WIN" << '\n';
        return;
    }

    if(((freq[b] + 1) / 2) % 2 == 1) {
        std::cout << "WIN" << '\n'; 
    } else {
        std::cout << ((N - freq[b]) % 2 == 0 ? "LOSE" : "WIN") << '\n';
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
