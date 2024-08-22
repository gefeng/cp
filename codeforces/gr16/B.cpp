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
    int ans = 0;
    for(int i = 0; i < n; ) {
        if(S[i] == '1') {
            i += 1;
            continue;
        }
        
        while(i < n && S[i] == '0') {
            i += 1;
        }
        ans += 1;
    }
     
    std::cout << std::min(2, ans) << '\n';
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
