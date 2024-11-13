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
    
    std::string S;
    std::cin >> S;

    auto is_pal = [&](int l, int r) {
        for(int i = l, j = r; i <= j; i++, j--) {
            if(S[i] != S[j]) {
                return false;
            }
        }
        return true;
    };

    int ans = -1;
    if(is_pal(0, N - 1)) {
        ans = 0; 
    } else {
        if(is_pal(0, N - 2) && is_pal(1, N - 1)) {
            ans = -1;
        } else {
            ans = 1;
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
