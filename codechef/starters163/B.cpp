#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::string S;
    std::string T;
    std::cin >> S >> T;

    if(N < M || S[0] != T[0] || S.back() != T.back()) {
        std::cout << "NO" << '\n';
        return;
    }

    auto shrink = [](std::string& s) {
        int n = s.size();
        std::string t = "";
        
        for(int i = 0; i < n; i++) {
            while(t.size() >= 3 && t[t.size() - 3] != s[i] && t[t.size() - 2] == t[t.size() - 1]) {
                t.pop_back();
                t.pop_back();
            }
            t.push_back(s[i]);
        }
        return t;
    };

    std::cout << (shrink(S) == shrink(T) ? "YES" : "NO") << '\n';
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
