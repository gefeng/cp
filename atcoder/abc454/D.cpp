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
    
    auto remove = [](const std::string& s) {
        int n = s.size();

        std::string stk;
        for(int i = 0; i < n; i++) {
            if(s[i] == ')') {
                if(stk.size() > 2) {
                    int size = stk.size();
                    if(stk[size - 1] == 'x' && stk[size - 2] == 'x' && stk[size - 3] == '(') {
                        for(int _ = 0; _ < 3; _++) {
                            stk.pop_back();
                        }
                        for(int _ = 0; _ < 2; _++) {
                            stk.push_back('x');
                        }
                    } else {
                        stk.push_back(s[i]);
                    }
                } else {
                    stk.push_back(s[i]);
                }
            } else {
                stk.push_back(s[i]);
            }
        }

        return stk;
    };

    std::cout << (remove(S) == remove(T) ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
