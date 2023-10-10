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

    int64_t P;
    std::cin >> P;
    P -= 1;
    
    int n = S.size();
    int cnt = 0;
    int cur = n;
    while(true) {
        if(P >= cur) {
            P -= cur;
        } else {
            break;
        }
        cur -= 1;
        cnt += 1;
    }
    
    std::string s;
    for(int i = 0; i < n; i++) {
        while(!s.empty() && s.back() > S[i] && cnt) {
            s.pop_back();
            cnt -= 1;
        }
        s.push_back(S[i]);
    }

    while(cnt) {
        s.pop_back();
        cnt -= 1;
    }

    std::cout << s[P];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
    std::cout << '\n';
}
