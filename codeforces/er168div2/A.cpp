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
    for(int i = 0; i < n - 1; i++) {
        if(S[i] == S[i + 1]) {
            for(char c = 'a'; c <= 'z'; c++) {
                if(c != S[i]) {
                    ans = S.substr(0, i + 1);
                    ans.push_back(c);
                    ans.append(S.substr(i + 1, n - 1 - i));
                    std::cout << ans << '\n';
                    return;
                }
            }
        }
    }

    ans = S;
    for(char c = 'a'; c <= 'z'; c++) {
        if(c != S.back()) {
            ans.push_back(c);
            break;
        }
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
