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
    int pre_l = -1;
    int pre_r = -1;
    int64_t ans = 0;
    for(int i = 0; i < n; ) {
        if(S[i] == '0') {
            i += 1;
            continue; 
        }
        
        int j = i;
        while(i < n && S[i] == '1') {
            i += 1; 
        }

        if(pre_l != -1) {
            int gap = j - pre_r - 1;
            ans += int64_t(pre_r - pre_l + 2) * gap; 
            pre_l += gap;
            pre_r = i - 1;
        } else {
            pre_l = j;
            pre_r = i - 1;
        }
    } 

    if(pre_r != -1 && pre_r != n - 1) {
        ans += int64_t(pre_r - pre_l + 2) * (n - pre_r - 1);
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
