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
    int max_l = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            std::string s = S.substr(i, j - i + 1);
            bool is_pal = true;
            for(int l = 0, r = s.size() - 1; l < r; l++, r--) {
                if(s[l] != s[r]) {
                    is_pal = false;
                    break;
                }
            }

            if(is_pal) {
                max_l = std::max(max_l, j - i + 1);
            }
        }
    }

    std::cout << max_l << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
