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

    std::sort(S.begin(), S.end());
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == S[0]) {
            cnt += 1;
        }
    }

    std::string ans = "";
    if(cnt == N) {
        ans = std::string(N / K + (N % K == 0 ? 0 : 1), S[0]); 
    } else if(cnt < K) {
        ans.push_back(S[K - 1]);
    } else {
        if(cnt == K) {
            ans.push_back(S[0]);
            if(S[K] == S.back()) {
                int len = N - K;
                for(int i = 0; i < len / K; i++) {
                    ans.push_back(S[K]);
                }
                if(len % K) {
                    ans.push_back(S[K]);
                }
            } else {
                for(int i = K; i < N; i++) {
                    ans.push_back(S[i]);
                }
            }
        } else {
            ans.push_back(S[0]);
            for(int i = K; i < N; i++) {
                ans.push_back(S[i]);
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
