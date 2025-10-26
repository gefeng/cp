#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    std::string S;
    std::cin >> S;
    
    int n = S.size();
    std::map<char, int> m;
    for(int i = 0; i < n; i++) {
        m[S[i]] += 1; 
    }

    auto get = [](char c) {
        if(c == 'R') {
            return 'P';
        }
        if(c == 'P') {
            return 'S';
        }
        return 'R';
    };

    int max_v = 0;
    char max_c = 'R';
    for(auto [c, f] : m) {
        if(f > max_v) {
            max_v = f;
            max_c = get(c);
        } 
    }

    std::string ans(n, max_c);
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
