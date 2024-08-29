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

    int n = S.size();
    std::vector<int> pos(26, -1);
    for(int i = 0; i < n; i++) {
        pos[S[i] - 'a'] = i;
    }

    int p = n;
    for(int i = 0; i < 26; i++) {
        if(pos[i] == -1) {
            continue;
        }
        p = std::min(p, pos[i]);
    } 
    
    std::cout << S.substr(p, n - p) << '\n';
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
