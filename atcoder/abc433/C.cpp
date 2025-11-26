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
    
    int64_t ans = 0;
    int n = S.size();
    int pre = 0;
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }

        if(j && S[j - 1] + 1 == S[j]) {
            int d = std::min(pre, i - j); 
            ans += d;
        }
        pre = i - j;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
