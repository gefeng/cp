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
    while(ans.size() < S.size()) {
        ans.append("io");
    }

    while(true) {
        int m = ans.size();
        int j = 0;
        int i = 0;
        while(i < n && j < m) {
            if(S[i] == ans[j]) {
                i += 1;
                j += 1;
            } else {
                j += 1;
            }
        }
        
        if(i == n) {
            std::cout << m - n << '\n';
            return;
        }
        ans.append("io");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
