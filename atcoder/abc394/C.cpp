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
        if(S[i] == 'A' && !ans.empty() && ans.back() == 'W') {
            int j = ans.size() - 1;
            for(; j >= 0 && ans[j] == 'W'; j--) {
                ans[j] = 'C';
            }
            ans[j + 1] = 'A';
            ans.push_back('C');
        } else {
            ans.push_back(S[i]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
