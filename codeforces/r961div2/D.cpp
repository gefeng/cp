#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C, K;
    std::cin >> N >> C >> K;

    std::string S;
    std::cin >> S;

    std::vector<int> bad(1 << C, 0);
    std::vector<int> cnt(C, 0);
    for(int l = 0, r = 0; r < N; r++) {
        cnt[S[r] - 'A'] += 1; 
        
        if(r - l + 1 > K) {
            cnt[S[l++] - 'A'] -= 1;
        }

        if(r - l + 1 == K) {
            int mask = 0;
            for(int i = 0; i < C; i++) {
                if(cnt[i] == 0) {
                    mask |= 1 << i; 
                }
            }
            bad[mask] = 1;
        }
    }

    for(int i = (1 << C) - 1; i >= 0; i--) {
        if(bad[i]) {
            for(int j = 0; j < C; j++) {
                if(i & (1 << j)) {
                    bad[i ^ (1 << j)] = 1;
                }
            }
        }
    }

    int ans = C;
    int last = S.back() - 'A';
    for(int i = 1; i < (1 << C); i++) {
        int c = __builtin_popcount(i);
        
        if(i & (1 << last) && !bad[i]) {
            ans = std::min(ans, c); 
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
