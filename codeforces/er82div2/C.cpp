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
    std::vector<int> seen(26, 0);
    int p = -1;
    for(int i = 0; i < n; i++) {
        if(ans.empty()) { 
            ans.push_back(S[i]);
            seen[S[i] - 'a'] = 1;
            p = 0;
            continue;
        }

        if(p - 1 >= 0 && ans[p - 1] == S[i]) {
            p -= 1;
            continue;
        }

        if(p + 1 < ans.size() && ans[p + 1] == S[i]) {
            p += 1;
            continue;
        }

        if(p == ans.size() - 1 && ans.size() < 26) {
            if(!seen[S[i] - 'a']) {
                ans.push_back(S[i]);
                seen[S[i] - 'a'] = 1;
                p += 1;
                continue;
            }
        }

        if(p - 1 < 0 && ans.size() < 26) {
            if(!seen[S[i] - 'a']) {
                ans = std::string(1, S[i]) + ans;
                seen[S[i] - 'a'] = 1;
                p = 0;
                continue;
            }
        }

        std::cout << "NO" << '\n';
        return;
    }

    for(int i = 0; i < 26; i++) {
        if(!seen[i]) {
            ans.push_back(char(i + 'a'));
        }
    }

    std::cout << "YES" << '\n';
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
