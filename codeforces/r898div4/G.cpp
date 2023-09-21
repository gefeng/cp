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
    int ans = 0;
    
    int max_cnt = 0;
    for(int i = 0; i < n; ) {
        if(S[i] == 'B') {
            int j = i;
            while(i < n && S[i] == 'B') {
                i += 1;
            }
            max_cnt = std::max(max_cnt, i - j);
        } else {
            i += 1;
        }
    }

    std::vector<int> a;
    for(int i = 0; i < n; ) {
        if(S[i] == 'A') {
            int j = i;
            while(i < n && S[i] == 'A') {
                i += 1;
            }
            a.emplace_back(i - j); 
        } else {
            i += 1;
        }
    }

    if(S[0] == 'B' || S.back() == 'B' || max_cnt > 1) {
        for(int f : a) {
            ans += f;
        } 
    } else {
        std::sort(a.begin(), a.end(), std::greater<int>());
        for(int f : a) {
            ans += f;
        }
        ans -= a.back();
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
