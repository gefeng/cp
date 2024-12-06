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

    std::array<int, 26> freq = {};
    for(int i = 0; i < N; i++) {
        freq[S[i] - 'a'] += 1;
    }

    std::vector<int64_t> fact(11, 1);
    for(int i = 1; i <= 10; i++) {
        fact[i] = fact[i - 1] * i;
    }

    int64_t prod = 1;
    for(int i = 0; i < 26; i++) {
        if(freq[i]) {
            prod *= fact[freq[i]];
        }
    }

    std::string ans = S;
    int64_t max_v = prod;
    int c1 = 0;
    int c2 = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(i != j && freq[i] && freq[j]) {
                int64_t a = freq[i] - 1;
                int64_t b = freq[j] + 1;
                int64_t x = prod / fact[freq[i]] / fact[freq[j]];
                x *= fact[a] * fact[b];
                if(x > max_v) {
                    max_v = x;
                    c1 = i;
                    c2 = j;
                }
            }
        }
    }

    if(c1 != -1) {
        for(int i = 0; i < N; i++) {
            if(ans[i] - 'a' == c1) {
                ans[i] = char(c2 + 'a');
                break;
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
