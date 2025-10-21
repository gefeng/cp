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
    int st = -1;
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            st = i;
            break;
        }
    }

    std::string max_s = "";
    int l = -1;
    int r = -1;
    for(int i = 0; i < st; i++) {
        std::string s = S.substr(i, n - st);
        std::string t(st, '1');
        
        for(int j = st; j < n; j++) {
            int b1 = S[j] - '0';
            int b2 = s[j - st] - '0';
            t.push_back(char((b1 ^ b2) + '0'));
        }

        if(max_s.empty() || t > max_s) {
            max_s = t;
            l = i;
            r = i + n - st - 1;
        }
    }

    if(l == -1) {
        l = n - 1;
        r = n - 1;
    }

    std::cout << 1 << ' ' << n << ' ' << l + 1 << ' ' << r + 1 << '\n';
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
