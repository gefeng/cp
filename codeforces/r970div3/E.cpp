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

    std::vector<std::array<int, 26>> save_eve(N);
    std::vector<std::array<int, 26>> save_odd(N);
    std::array<int, 26> cnt_eve = {};
    std::array<int, 26> cnt_odd = {};
    for(int i = N - 1; i >= 0; i--) {
        if(i % 2 == 0) {
            cnt_eve[S[i] - 'a'] += 1;
        } else {
            cnt_odd[S[i] - 'a'] += 1;
        }

        for(int j = 0; j < 26; j++) {
            save_eve[i][j] = cnt_eve[j];
            save_odd[i][j] = cnt_odd[j];
        }
    }
    
    for(int i = 0; i < 26; i++) {
        cnt_eve[i] = 0;
        cnt_odd[i] = 0;
    }

    int ans = N;
    if(N % 2 == 0) {
        int max_e = 0;
        int max_o = 0;
        for(int i = 0; i < 26; i++) {
            max_e = std::max(max_e, save_eve[0][i]);
            max_o = std::max(max_o, save_odd[0][i]);
        }
        ans = (N + 1) / 2 - max_e + N / 2 - max_o;
    } else {
        for(int i = 0; i < N; i++) {
            int eve = N;
            int odd = N;
            for(int j = 0; j < 26; j++) {
                int l = i == 0 ? 0 : cnt_eve[j]; 
                int r = i + 1 == N ? 0 : save_odd[i + 1][j];
                eve = std::min(eve, (i + 1) / 2 - l + (N - 1 - i) / 2 - r);

                l = i == 0 ? 0 : cnt_odd[j];
                r = i + 1 == N ? 0 : save_eve[i + 1][j];
                odd = std::min(odd, i / 2 - l + (N - 1 - i + 1) / 2 - r);
            }

            ans = std::min(ans, eve + odd + 1);

            if(i % 2 == 0) {
                cnt_eve[S[i] - 'a'] += 1;
            } else {
                cnt_odd[S[i] - 'a'] += 1;
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
