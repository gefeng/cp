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
    int now = 0;
    int pre = -1;
    std::vector<int> stk;
    stk.push_back(-1);
    
    for(int i = 0; i < N * 2; i++) {
        if(S[i] == '(') {
            if(pre != now) {
                ans += 1;
            }
            pre = now;
            stk.push_back(now++);
        } else {
            stk.pop_back();
            now -= 1;
            pre = now;
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
