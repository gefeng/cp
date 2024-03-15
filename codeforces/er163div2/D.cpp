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
    
    for(int i = 1; i <= n / 2; i++) {
        int cnt = 0;
        for(int j = 0; j + i < n; j++) {
            if(S[j] == S[j + i] || S[j] == '?' || S[j + i] == '?') {
                cnt += 1; 
            } else {
                cnt = 0;
            } 

            if(cnt == i) {
                ans = cnt;
                break;
            }
        }
    }

    std::cout << ans * 2 << '\n';
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
