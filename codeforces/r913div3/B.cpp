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
    std::vector<int> s1;
    std::vector<int> s2;
    
    for(int i = 0; i < n; i++) {
        if(S[i] >= 'a' && S[i] <= 'z') {
            if(S[i] == 'b') {
                if(!s1.empty()) {
                    s1.pop_back();
                }
            } else {
                s1.push_back(i);
            }
        } else {
            if(S[i] == 'B') {
                if(!s2.empty()) {
                    s2.pop_back();
                }
            } else {
                s2.push_back(i);
            }
        }
    }

    std::string ans = "";
    for(int i = 0, j = 0; i < s1.size() || j < s2.size(); ) {
        if(i == s1.size()) {
            ans.push_back(S[s2[j++]]);
        } else if(j == s2.size()) {
            ans.push_back(S[s1[i++]]);
        } else {
            ans.push_back(s1[i] < s2[j] ? S[s1[i++]] : S[s2[j++]]);
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
