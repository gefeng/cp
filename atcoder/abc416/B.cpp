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
    std::string ans(n, '.');
    
    for(int i = 0; i < n; i++) {
        if(S[i] == '#') {
            ans[i] = '#';
        }
    }

    int pre = -1;
    for(int i = 0; i < n; i++) {
        if(pre == -1 && ans[i] == '.') {
            ans[i] = 'o';
            pre = 0;
        }        
        if(ans[i] == '#') {
            pre = -1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
