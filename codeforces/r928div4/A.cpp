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

    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        if(S[i] == 'A') {
            cnt += 1;
        }
    }

    std::cout << (cnt > 2 ? 'A' : 'B') << '\n';
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
