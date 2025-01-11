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
        int j = i;
        while(i < n && S[i] == S[j]) {
            i += 1;
        }
        if(S[j] == '0') {
            ans += (i - j + 1) / 2;
        } else {
            ans += i - j;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
