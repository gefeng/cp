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
    
    std::vector<int> ans(N, 0);
    for(int i = 0, j = N, k = 1; i < N; i++) {
        if(S[i] == '0') {
            ans[i] = j--;
        } else {
            ans[i] = k++;
        }
    }

    int cnt = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(S[r] == '0') {
            cnt += 1;
        } 
        if(r - l + 1 > K) {
            cnt -= S[l] == '0' ? 1 : 0;
            l += 1;
        }
        if(r - l + 1 == K) {
            if(cnt == 0) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
