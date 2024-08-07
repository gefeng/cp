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
    std::array<int, 26> seen = {};
    for(int i = 0; i < n; i++) {
        if(!seen[S[i] - 'a']) {
            seen[S[i] - 'a'] = 1;
        }
    }

    for(char c = 'a'; c <= 'z'; c++) {
        if(!seen[c - 'a']) {
            continue;
        }

        int pre = -1;
        std::array<int, 26> a = {};
        for(int i = 0; i < n; i++) {
            if(S[i] == c) {
                if(pre != -1) {
                    for(int j = 0; j < 26; j++) {
                        if(j == c - 'a') {
                            continue;
                        }
                        if(seen[j] && !a[j]) {
                            std::cout << "No" << '\n';
                            return;
                        }
                    }
                }
                pre = i;
                a.fill(0);
            } else {
                a[S[i] - 'a'] = 1; 
            }
        }
    }

    std::cout << "Yes" << '\n';
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
