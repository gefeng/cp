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

    std::string S;
    std::cin >> S;

    std::string stk = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == 'Q') {
            stk.push_back(S[i]);
        } else {
            if(!stk.empty() && stk.back() == 'Q') {
                stk.pop_back();
            }
        }
    }

    std::cout << (stk.empty() ? "Yes" : "No") << '\n';
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
