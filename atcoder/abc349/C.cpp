#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S, T;
    std::cin >> S >> T;

    auto is_subseq = [&](std::string s) {
        int n = S.size();
        int m = s.size();
        int j = 0;
        for(int i = 0; i < n && j < m; i++) {
            if(S[i] - 'a' == s[j] - 'A') {
                j += 1;
            }
        }
        return j == m;
    };
    
    if(T.back() == 'X') {
        std::cout << (is_subseq(T.substr(0, 2)) ? "Yes" : "No") << '\n';
    } else {
        std::cout << (is_subseq(T) ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
