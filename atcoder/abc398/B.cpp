#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::array<int, 7> A;

    for(int i = 0; i < 7; i++) {
        std::cin >> A[i];
    }

    std::array<int, 14> freq = {};
    for(int i = 0; i < 7; i++) {
        freq[A[i]] += 1; 
    }

    for(int i = 1; i <= 13; i++) {
        if(freq[i] >= 3) {
            for(int j = 1; j <= 13; j++) {
                if(i != j && freq[j] >= 2) {
                    std::cout << "Yes" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
