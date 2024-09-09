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

    std::vector<std::string> ans;
    
    int n = S.size();
    while(true) {
        std::string res = "";
        for(int i = 0; i < n; i++) {
            if(S[i] != T[i]) {
                std::string s(S); 
                s[i] = T[i];
                if(res.empty() || res > s) {
                    res = s;
                }
            }
        }

        if(res.empty()) {
            break;
        }
        ans.push_back(res);
        S = res;
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
