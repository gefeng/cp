#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;
    
    std::string S;
    std::cin >> S;

    if(N % K != 0) {
        std::cout << -1 << '\n';
        return;
    }

    auto is_good = [&](std::string& s) {
        std::array<int, 26> freq = {};
        for(int i = 0; i < N; i++) {
            freq[s[i] - 'a'] += 1;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] % K != 0) {
                return false;
            }
        }
        return true;
    };

    if(is_good(S)) {
        std::cout << S << '\n';
        return;
    }

    std::string ans = "";
    std::array<int, 26> freq = {};
    int p = -1;
    char which = -1;
    int extra = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != 'z') {
            for(char c = S[i] + 1; c <= 'z'; c++) {
                std::array<int, 26> a = freq;
                a[c - 'a'] += 1;

                int need = 0;
                for(int j = 0; j < 26; j++) {
                    need += (K - a[j] % K) % K;
                }
                if(need <= N - 1 - i && (N - 1 - i - need) % K == 0) {
                    p = i;
                    which = c;
                    extra = N - 1 - i - need;
                    break;
                }
            }
        }
        freq[S[i] - 'a'] += 1;
    }

    if(p == -1) {
        std::cout << -1 << '\n';
        return;
    }

    freq.fill(0);
    for(int i = 0; i < p; i++) {
        ans.push_back(S[i]);
        freq[S[i] - 'a'] += 1;
    }

    ans.push_back(which);
    freq[which - 'a'] += 1;
    for(int i = 0; i < extra; i++) {
        ans.push_back('a');
    }

    for(int i = 0; i < 26; i++) {
        int rem = (K - freq[i] % K) % K;
        for(int j = 0; j < rem; j++) {
            ans.push_back(char(i + 'a'));
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
