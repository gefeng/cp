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
    
    std::array<int, 10> freq = {};
    for(int i = 0; i < 10; i++) {
        freq[S[i] - '0'] += 1;
    }

    std::string ans = "";
    for(int i = 0; i < 10; i++) {
        for(int j = 9 - i; j < 10; j++) {
            if(freq[j]) {
                ans.push_back((char)(j + '0'));
                freq[j] -= 1;
                break;
            }
        }
    }

    std::cout << ans << '\n';
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
