#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;
    
    std::sort(S.begin(), S.end());

    auto is_pal = [](std::string& s) {
        for(int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if(s[l] != s[r]) {
                return false;
            } 
        }
        return true;
    };

    int ans = 0;
    do {
        bool good = true;
        for(int i = 0; i <= N - K; i++) {
            std::string t = S.substr(i, K);
            if(is_pal(t)) {
                good = false;
                break;
            } 
        }
        if(good) {
            ans += 1;
        }
    } while(std::next_permutation(S.begin(), S.end()));

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
