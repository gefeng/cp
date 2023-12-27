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

    if(N == 1) {
        std::cout << (A[0] > 1 ? "Alice" : "Bob") << '\n';
        return;
    }

    int64_t sum = 0;
    int parity = 0;
    for(int i = 0; i < N; i++) {
        sum += A[i];
        if(i % 2 == 0) {
            parity = (parity + A[i]) % 2;
        }
    } 

    if(sum % 2 == 1) {
        std::cout << "Bob" << '\n';
        return;
    }

    int64_t steps = sum / 2 - 1;
    if(parity) {
        std::cout << (steps % 2 == 1 ? "Alice" : "Bob") << '\n';
    } else {
        std::cout << (steps % 2 == 0 ? "Alice" : "Bob") << '\n';
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
