#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;
    
    std::array<int, 26> freq = {};
    for(int i = 0; i < 2; i++) {
        freq[S[i] - 'a'] += 1;
        freq[T[i] - 'a'] += 1;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i]) {
            cnt += 1;
        }
    }

    std::cout << cnt - 1 << '\n';
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
