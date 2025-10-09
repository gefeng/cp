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
    if(S[0] != '9') {
        for(int i = 0; i < N; i++) {
            ans.push_back(static_cast<char>('9' - S[i] + '0'));
        }
    } else {
        int c = 0;
        for(int i = N - 1; i >= 0; i--) {
            int x = i == N - 1 ? 1 : 8;
            int y = S[i] - '0';
            x = (x - c + 10) % 10;
            
            if(x < y) {
                x += 10;
                c = 1;
            } else {
                c = 0;
            }

            ans.push_back(static_cast<char>(x - y + '0'));
        }
        std::ranges::reverse(ans);
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
