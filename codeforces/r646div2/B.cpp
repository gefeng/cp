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
    int ans = n;
    std::vector<int> prefix_0(n + 1, 0);
    std::vector<int> prefix_1(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix_0[i + 1] = prefix_0[i] + S[i] - '0';
        prefix_1[i + 1] = prefix_1[i] + (S[i] == '0' ? 1 : 0);
    }

    int one = 0;
    int zero = 0;
    for(int i = 0; i <= n; i++) {
        if(i) {
            one += S[n - i] == '0' ? 1 : 0;
            zero += S[n - i] == '1' ? 1 : 0;
        } 

        ans = std::min(ans, prefix_0[n - i] + one);
        ans = std::min(ans, prefix_1[n - i] + zero);
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
