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
    std::string stk = "";
    
    for(int i = 0; i < n; i++) {
        if(S[i] == ')' && !stk.empty() && stk.back() == '(') {
            stk.pop_back();
            continue;
        }
        if(S[i] == ']' && !stk.empty() && stk.back() == '[') {
            stk.pop_back();
            continue;
        }
        if(S[i] == '>' && !stk.empty() && stk.back() == '<') {
            stk.pop_back();
            continue;
        }

        stk.push_back(S[i]);
    }

    std::cout << (stk.empty() ? "Yes" : "No") << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
