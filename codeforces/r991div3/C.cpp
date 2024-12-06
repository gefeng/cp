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
    std::vector<int> dp(10, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        std::vector<int> ndp(10, 0);
        for(int j = 0; j < 10; j++) {
            if(!dp[j]) {
                continue; 
            }
            ndp[(j + S[i] - '0') % 9] = 1;
 
            if(S[i] == '2') {
                ndp[(j + 4) % 9] = 1;
            } else if(S[i] == '3') {
                ndp[(j + 9) % 9] = 1;
            }
        }
        std::swap(dp, ndp);
    }

    std::cout << (dp[0] ? "Yes" : "No") << '\n';
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
