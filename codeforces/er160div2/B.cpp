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
    int cnt_one = 0;
    int cnt_zero = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            cnt_zero += 1;
        } else {
            cnt_one += 1;
        }
    }

    if(cnt_one == cnt_zero) {
        std::cout << 0 << '\n'; 
        return;
    }

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(S[i] == '1') {
            if(cnt_zero == 0) {
                break;
            }
            cnt_zero -= 1;
        } else {
            if(cnt_one == 0) {
                break;
            }
            cnt_one -= 1;
        }
        cnt += 1;
    }

    std::cout << n - cnt << '\n';
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
