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
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            if(pre != 1) {
                ans.push_back('1');
                pre = 1;
            } else {
                ans.push_back('0');
                pre = 0;
            }
        } else {
            if(pre != 2) {
                ans.push_back('1');
                pre = 2;
            } else {
                ans.push_back('0');
                pre = 1;
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
