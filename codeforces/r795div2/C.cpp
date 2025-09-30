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

    int ans = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(i + 1 < N) {
            ans += (S[i] - '0') * 10 + S[i + 1] - '0';
        }
        cnt += S[i] - '0';
    }

    if(cnt == 0) {
        std::cout << ans << '\n';
        return;
    }

    if(cnt == 1) {
        for(int i = 0; i < N; i++) {
            if(S[i] == '1') {
                if(N - 1 - i <= K) {
                    S[i] = '0';
                    S[N - 1] = '1';
                    break;
                }
                if(i <= K) {
                    S[i] = '0';
                    S[0] = '1';
                }
            }
        }
        ans = 0;
        for(int i = 0; i < N - 1; i++) {
            ans += (S[i] - '0') * 10 + S[i + 1] - '0';
        }
        std::cout << ans << '\n';
        return;
    }

    int first = -1;
    int last = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            first = first == -1 ? i : first;
            last = i;
        }
    }

    if(N - 1 - last <= K) {
        S[last] = '0';
        S[N - 1] = '1';
        K -= N - 1 - last;
    }

    if(first <= K) {
        S[first] = '0';
        S[0] = '1';
    }
    
    ans = 0;
    for(int i = 0; i < N - 1; i++) {
        ans += (S[i] - '0') * 10 + S[i + 1] - '0';
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
