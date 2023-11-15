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
    int rem = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '?') {
            cnt += 1;
        } else {
            rem += S[i] - '0';
            rem %= 9;
        }
    }

    if(S[0] == '?') {
        std::string ans = "1";         
        for(int i = 0; i < cnt - 1; i++) {
            ans.push_back('0');
        }

        std::cout << ans << '\n';
    } else {
        std::string ans = "";
        for(int i = 0; i < cnt - 1; i++) {
            ans.push_back('1');
        }

        ans.push_back(rem == 0 ? '2' : '1');
        std::cout << ans << '\n';
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
