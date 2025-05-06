#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(4e18);
constexpr int64_t MAX = int64_t(1e18);

void run_case() {
    int N;
    int64_t K;
    std::cin >> N >> K;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> dp_1(N, -INF);
    std::vector<int64_t> dp_2(N, -INF);
    int64_t max_s = -INF;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1; 
        }
        
        if(S[j] == '0') {
            continue; 
        }

        for(int k = j; k < i; k++) {
            dp_1[k] = k == j ? A[k] : std::max(A[k], dp_1[k - 1] + A[k]);
            max_s = std::max(max_s, dp_1[k]);
            if(max_s > K) {
                std::cout << "No" << '\n';
                return;
            }
        }

        for(int k = i - 1; k >= j; k--) {
            dp_2[k] = k == i - 1 ? A[k] : std::max(A[k], dp_2[k + 1] + A[k]);
            max_s = std::max(max_s, dp_2[k]);
            if(max_s > K) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    if(max_s == K) {
        std::cout << "Yes" << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << (S[i] == '1' ? A[i] : -MAX) << " \n"[i == N - 1];
        }
        return;
    }

    std::vector<int64_t> ans(N, 0);
    int p = -1;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }
        
        if(S[j] == '1') {
            continue;
        }
        
        int64_t l = j == 0 ? 0 : dp_1[j - 1];
        int64_t r = i == N ? 0 : dp_2[i];
    
        int64_t x = K - l;
        if(x <= K) {
            if(i - j > 1 || (i - j == 1 && r <= 0)) {
                ans[j] = x; 
                p = j;
                break;
            }
        }

        x = K - r;
        if(x <= K) {
            if(i - j > 1 || (i - j == 1 && l <= 0)) {
                ans[i - 1] = x;
                p = i - 1;
                break;
            }
        }

        x = K - l - r;
        if(x <= K) {
            ans[j] = x;
            p = j;
            break;
        }

        ans[j] = K;
        p = j;
        break;
    }

    if(p == -1) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        if(S[i] == '0' && i != p) {
            ans[i] = -MAX;
        }
        if(S[i] == '1') {
            ans[i] = A[i];
        }
    }

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
