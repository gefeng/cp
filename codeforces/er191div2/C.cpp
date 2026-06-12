#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    auto count = [](std::string& s) {
        int res = 0;
        std::string stk = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(!stk.empty() && stk.back() == '(') {
                    stk.pop_back();
                    res += 2;
                    continue;
                } 
                stk.push_back(s[i]);
            } else {
                stk.push_back(s[i]);
            }
        }
        return res;
    };

    int removed = 0;
    int min_l = N + 1;
    std::string ans = "";
    std::string s = "";
    std::string cand = "";

    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == ')' && removed < K) {
            removed++;
            ans.push_back('1');
        } else {
            ans.push_back('0');
            s.push_back(S[i]);
        }
    }

    std::ranges::reverse(s);
    std::ranges::reverse(ans);
    min_l = count(s);

    removed = 0;
    cand = "";
    s = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            if(removed < K) {
                removed++;
                cand.push_back('1');
                std::string suffix = "";
                std::string cand_s = "";
                int k = K - removed;
                for(int j = N - 1; j > i; j--) {
                    if(S[j] == ')' && k) {
                        k--;
                        cand_s.push_back('1');
                    } else {
                        suffix.push_back(S[j]);
                        cand_s.push_back('0');
                    }
                }
                std::ranges::reverse(suffix);
                std::string t = s + suffix;
                int len = count(t);
                if(len < min_l) {
                    min_l = len;
                    std::ranges::reverse(cand_s);
                    ans = cand + cand_s;
                }
            } else {
                cand.push_back('0');
            }
        } else {
            s.push_back(')');
            cand.push_back('0');
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
