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

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '*') {
            if(++cnt == 2) {
                break;
            }
        } else if(S[i] == '@') {
            ans += 1;
            cnt = 0;
        } else {
            cnt = 0;
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
