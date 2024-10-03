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

    std::array<int, 26> pos = {};
    for(int i = 0; i < 26; i++) {
        pos[S[i] - 'A'] = i;
    }

    int p = pos[0];
    int ans = 0;
    for(int i = 1; i < 26; i++) {
        ans += std::abs(p - pos[i]); 
        p = pos[i];
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
