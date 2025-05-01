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

    std::string ans(N, '?');
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            ans[i] = 'o';
            K -= 1;
        } else if(S[i] == '.') {
            ans[i] = '.';
        } else {
            if(i && S[i - 1] == 'o') {
                ans[i] = '.';
                S[i] = '.';
            } else if(i + 1 < N && S[i + 1] == 'o') {
                ans[i] = '.';
                S[i] = '.';
            }
        }
    }

    if(K == 0) {
        for(int i = 0; i < N; i++) {
            if(S[i] == '?') {
                ans[i] = '.';
            }
        }
        std::cout << ans << '\n';
        return;
    }

    int max_0 = 0;
    for(int i = 0; i < N; ) {
        if(S[i] == '?') {
            int j = i;
            while(i < N && S[i] == S[j]) {
                i += 1;
            }
            max_0 += (i - j + 1) / 2;
        } else {
            i += 1;
        }
    }

    if(max_0 == K) {
        for(int i = 0; i < N; ) {
            if(S[i] == '?') {
                int j = i;
                while(i < N && S[i] == S[j]) {
                    i += 1;
                }
                if((i - j) % 2 == 1) {
                    for(int k = j; k < i; k += 2) {
                        ans[k] = 'o';
                        if(k + 1 < i) {
                            ans[k + 1] = '.';
                        }
                    }
                }
            } else {
                i += 1;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
