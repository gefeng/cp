#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(1e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;
    
    auto count_inversion = [](std::string& s) {
        int n = s.size();
        int64_t res = 0;
        int cnt_1 = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                res += cnt_1;
            } else {
                cnt_1 += 1;
            }
        }
        return res;
    };

    int64_t cnt_inv = count_inversion(S);
    int64_t ans = cnt_inv;

    for(int a = 0; a <= K; a++) {
        int b = K - a;
        std::string s(S);
        
        int cnt = a;
        int p = 0;
        for(int i = 0; i < N; i++) {
            if(cnt == 0) {
                p = -1;
                break;
            }
            if(s[i] == '1') {
                s[i] = '0';
                cnt -= 1;
            }
        }
        
        if(cnt) {
            std::cout << 0 << '\n';
            return;
        }

        cnt = b;
        for(int i = N - 1; i >= p; i--) {
            if(cnt == 0) {
                break;
            } 
            if(s[i] == '0') {
                s[i] = '1';
                cnt -= 1;
            }
        }

        ans = std::min(ans, count_inversion(s));
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
