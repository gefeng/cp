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
    for(int l = 0, r = N - 1; l < r; l++, r--) {
        if(S[l] != S[r]) {
            cnt += 1;
        }
    }

    std::string ans = "";
    for(int i = 0; i <= N; i++) {
        if(i < cnt) {
            ans.push_back('0');
        } else {
            int x = i - cnt;
            int y = N - 2 * cnt;
            
            if(N % 2 == 0) {
                if(y >= x) {
                    ans.push_back(x % 2 == 0 ? '1' : '0');
                } else {
                    ans.push_back('0');
                }
            } else {
                ans.push_back(y >= x ? '1' : '0');
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
