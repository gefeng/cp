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

    int bal = 0; 
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) {
            if(bal == 0) {
                S[i] = '(';
                bal += 1;
            } else {
                S[i] = ')';
                bal -= 1;
            }
        } else {
            if(S[i] == '(') {
                bal += 1;
            } else {
                bal -= 1;
            }
        }
    }

    int64_t ans = 0;
    std::vector<int> stk;
    for(int i = 0; i < N; i++) {
        if(S[i] == ')') {
            assert(!stk.empty());
            ans += i - stk.back();
            stk.pop_back();
        } else {
            stk.push_back(i);
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
