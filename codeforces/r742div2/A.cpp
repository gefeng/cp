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

    std::string ans = "";
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            ans.append("LR");
            i += 1;
        } else {
            if(S[i] == 'U') {
                ans.push_back('D');
            } else {
                ans.push_back('U');
            }
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
