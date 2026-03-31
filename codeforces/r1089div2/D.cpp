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

    std::string S, T;
    std::cin >> S >> T;

    S = "(" + S + ")";
    T = "(" + T + ")";

    auto count_leaves = [](std::string& s) {
        int cnt = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == ')' && s[i - 1] == '(') {
                cnt++;
            }
        }
        return cnt;
    };

    auto count_depth = [](std::string& s) {
        int n = s.size();
        std::vector<int> cnt(n, 0);
        std::vector<int> stk;
        int now = 0;
        for(int i = 0; i < n; i++) {
            if(stk.empty()) {
                stk.push_back(now++);
            } else {
                if(s[i] == '(') {
                    stk.push_back(now++);
                } else {
                    stk.pop_back();
                    now--;
                    if(!stk.empty()) {
                        cnt[stk.back()]++;
                    }
                }
            }
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(cnt[i] > 1) {
                res = i;
                break;
            }
        }
        return res;
    };

    if(count_leaves(S) != count_leaves(T)) {
        std::cout << "NO" << '\n';
        return;
    }

    std::cout << (count_depth(S) == count_depth(T) ? "YES" : "NO") << '\n'; 
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
