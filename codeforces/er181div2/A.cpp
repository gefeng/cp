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
    std::string ans = "";
    for(int i = 0; i < n; i++) {
        if(S[i] == 'T') {
            ans.push_back('T');
        }
    }

    for(int i = 0; i < n; i++) {
        if(S[i] != 'T') {
            ans.push_back(S[i]);
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
