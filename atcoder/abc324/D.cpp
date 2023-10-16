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

    std::array<int, 10> cnt_s = {};
    for(char c : S) {
        cnt_s[c - '0'] += 1;
    }
    
    int64_t max_v = 0;
    for(int i = 0; i < N; i++) {
        max_v = max_v * 10 + 9;
    }

    int ans = 0;
    for(int64_t i = 0; i * i <= max_v; i++) {
        int64_t sq = i * i;
        std::array<int, 10> cnt_t = {};
        bool ok = true;
        while(sq) {
            cnt_t[sq % 10] += 1; 
            sq /= 10;
        }

        for(int j = 0; j < 10; j++) {
            if(j == 0) {
                if(cnt_s[j] < cnt_t[j]) {
                    ok = false;
                } 
            } else {
                if(cnt_s[j] != cnt_t[j]) {
                    ok = false;      
                    break;
                }
            }
        }

        if(ok) {
            ans += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
