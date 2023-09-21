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

    std::string t = "abc";
    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] != t[i]) {
            cnt += 1;
        }
    }

    if(cnt == 0 || cnt == 2) {
        std::cout << "YES" << '\n';
    } else {
        std::cout << "NO" << '\n';
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
