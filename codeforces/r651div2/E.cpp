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

    std::string S, T;
    std::cin >> S >> T;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += S[i] - '0'; 
        cnt -= T[i] - '0';
    }

    if(cnt != 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> a;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0' && T[i] == '1') {
            a.push_back(0);
        } else if(S[i] == '1' && T[i] == '0') {
            a.push_back(1);
        }
    }

    if(a.empty()) {
        std::cout << 0 << '\n';
        return;
    }

    int n = a.size();
    int ans = 0;
    int cnt_0 = 0;
    int cnt_1 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) {
            if(cnt_1) {
                cnt_1 -= 1;
                cnt_0 += 1;
            } else {
                cnt_0 += 1;
                ans += 1;
            }
        } else {
            if(cnt_0) {
                cnt_0 -= 1;
                cnt_1 += 1;
            } else {
                cnt_1 += 1;
                ans += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
