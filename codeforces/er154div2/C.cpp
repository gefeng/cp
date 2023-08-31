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
    int len = 0;
    int pre_one = -1;
    int pre_zero = -1;
    int cnt_add = 0;
    int last_dec = n + 1;
    for(int i = 0; i < n; i++) {
        if(S[i] == '+') {
            len += 1;
            cnt_add += 1;
        } else if(S[i] == '-') {
            len -= 1;
            if(len < last_dec) {
                last_dec = n + 1;
            }
            cnt_add = std::max(0, cnt_add - 1);
        } else if(S[i] == '0') {
            if(len < 2) {
                std::cout << "NO" << '\n';
                return;
            }

            if(pre_one != -1) {
                if(cnt_add == 0) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }

            last_dec = std::min(last_dec, len);
            pre_zero = i;
        } else {
            if(pre_zero != -1) {
                if(last_dec != n + 1) {
                    std::cout << "NO" << '\n';
                    return;
                }
            }

            pre_one = i;
            cnt_add = 0;
        }
    }

    std::cout << "YES" << '\n';
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
