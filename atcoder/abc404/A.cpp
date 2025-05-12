#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    std::array<int, 26> freq = {};
    for(int i = 0; i < S.size(); i++) {
        freq[S[i] - 'a'] += 1;
    }

    for(int i = 0; i < 26; i++) {
        if(freq[i] == 0) {
            std::cout << (char)(i + 'a') << '\n';
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
