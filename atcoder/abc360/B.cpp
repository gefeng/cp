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

    int n = S.size();
    for(int w = 1; w < n; w++) {
        for(int c = 0; c < w; c++) {
            std::string s = "";
            for(int i = 0; i < n; i += w) {
                if(i + c < n) {
                    s.push_back(S[i + c]);
                }
            }
            if(s == T) {
                std::cout << "Yes" << '\n';
                return;
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
