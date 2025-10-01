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

    std::vector<std::string> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::string S;
    std::cin >> S;
    
    std::array<int, 26> freq = {};
    for(std::string& s : A) {
        for(char c : s) {
            freq[c - 'a'] += 1;
        }
    }

    for(char c : S) {
        freq[c - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 == 1) {
            std::cout << static_cast<char>(i + 'a') << '\n';
            return;
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
