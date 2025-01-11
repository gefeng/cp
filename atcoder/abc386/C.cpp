#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int K;
    std::cin >> K;

    std::string S, T;
    std::cin >> S >> T;
    
    int n = S.size();
    int m = T.size();
    
    if(n == m) {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] != T[i]) {
                cnt += 1;
            }
        }
        std::cout << (cnt <= 1 ? "Yes" : "No") << '\n';
        return;
    }

    if(n - 1 == m) {
        bool skip = false;
        for(int i = 0, j = 0; i < n && j < m; ) {
            if(S[i] != T[j]) {
                if(skip) {
                    std::cout << "No" << '\n';
                    return;
                } 
                skip = true;
                i += 1;
            } else {
                i += 1;
                j += 1;
            }
        }

        std::cout << "Yes" << '\n';
        return;
    }

    if(m - 1 == n) {
        bool skip = false;
        for(int i = 0, j = 0; i < n && j < m; ) {
            if(S[i] != T[j]) {
                if(skip) {
                    std::cout << "No" << '\n';
                    return;
                } 
                skip = true;
                j += 1;
            } else {
                i += 1;
                j += 1;
            }
        }

        std::cout << "Yes" << '\n';
        return;
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
