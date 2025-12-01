#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    std::set<std::string> dict;
    std::vector<std::string> A;
    bool reading_dict = true;
    for(std::string S; std::getline(std::cin, S); ) {
        if(S.empty()) {
            reading_dict = false;
            continue;
        } 
        
        if(reading_dict) {
            int n = S.size();
            for(int i = 0; i < n; ) {
                while(i < n && (S[i] < 'a' || S[i] > 'z')) {
                    i += 1;
                }
                
                std::string s = "";
                while(i < n && S[i] >= 'a' && S[i] <= 'z') {
                    s.push_back(S[i++]);
                }
                if(!s.empty()) {
                    dict.insert(s);
                }
            }
        } else {
            A.push_back(S); 
        }
    }

    auto solve = [&](std::string& s) {
        int n = s.size();
        std::vector<int64_t> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(dp[j]) {
                    std::string t = s.substr(j, i - j);
                    if(dict.find(t) != dict.end()) {
                        dp[i] += dp[j];
                    }
                }
            } 
        }
        return dp[n];
    };

    int64_t ans = 0;
    for(std::string& s : A) {
        ans += solve(s);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
