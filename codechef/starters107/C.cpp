#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    auto solve = [](std::string s, char t) {
        int n = s.size();
        int cnt_eve = 0;
        int cnt_odd = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == t) {
                if(i % 2 == 0) {
                    cnt_eve += 1;
                } else {
                    cnt_odd += 1;
                }
            }
        }

        return cnt_eve == cnt_odd;
    };

    std::cout << (solve(S, '0') || solve(S, '1') ? "Yes" : "No") << '\n';
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
