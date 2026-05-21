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
    int ans = n;
    int cnt4 = 0;
    std::string s = "";
    for(int i = 0; i < n; i++) {
        if(S[i] == '4') {
            cnt4++;
        } else {
            s.push_back(S[i]);
        }
    }

    while(!s.empty() && s.back() != '2') {
        s.pop_back();
    }

    n = s.size();
    int tot = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '2') {
            tot++;
        }
    }
    
    ans = std::min(ans, tot + cnt4);
    ans = std::min(ans, cnt4 + n - tot);

    for(int i = 0; i < n; i++) {
        if(s[i] == '2') {
            cnt++;
        }
        ans = std::min(ans, i + 1 - cnt + cnt4 + tot - cnt);
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
