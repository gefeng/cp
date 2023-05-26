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

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            cnt += 1;
        }
    }
    
    if(cnt != N - cnt) {
        std::cout << -1 << '\n';
        return;
    }

    auto is_bal = [](std::string& s) {
        int n = s.size();
        int bal = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                bal += 1; 
            } else {
                bal -= 1;
            } 

            if(bal < 0) {
                return false;
            }
        }

        return bal == 0;
    };

    std::string rs = S;
    std::reverse(rs.begin(), rs.end());

    if(is_bal(S) || is_bal(rs)) {
        std::cout << 1 << '\n'; 
        for(int i = 0; i < N; i++) {
            std::cout << 1 << " \n"[i == N - 1];
        }
    } else {
        std::cout << 2 << '\n';

        std::vector<std::pair<char, int>> stack;
        std::vector<int> ans(N, 1);
        for(int i = 0; i < N; i++) {
            if(!stack.empty() && stack.back().first == '(' && S[i] == ')') {
                stack.pop_back();
            } else {
                stack.emplace_back(S[i], i);
            }
        }

        while(!stack.empty()) {
            ans[stack.back().second] = 2;            
            stack.pop_back();
        }

        for(int i = 0; i < N; i++) {
            std::cout << ans[i] << " \n"[i == N - 1];
        }
    }
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
