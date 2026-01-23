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
    std::string free = "";

    for(int i = 0; i < n; i++) {
        while(!ans.empty() && ans.back() > S[i]) {
            free.push_back(std::min('9', static_cast<char>(ans.back() + 1)));
            ans.pop_back();
        }
        ans.push_back(S[i]);
    }

    ans.append(free);
    std::ranges::sort(ans);

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
