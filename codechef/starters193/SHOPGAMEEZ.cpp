#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <queue>

constexpr int64_t MOD = int64_t(1e9) + 7;
constexpr int INF = int(2e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::string S;
    std::cin >> S;

    std::ranges::sort(A, std::greater<std::pair<int, int>>());
    
    int64_t ans = 0;
    if(S.back() == '0') {
        int cnt = 0;
        for(int i = K - 1; i >= 0; i--) {
            if(S[i] == '0') {
                cnt += 1;
            } else {
                break;
            }
        }

        std::vector<int> seen(N, 0);
        for(int i = 0; i < K; i++) {
            ans += A[i].first;
            ans %= MOD;
            seen[A[i].second] = 1;
        }

        bool missing = false;
        for(int i = N - 1; i >= N - K + cnt - 1; i--) {
            if(!seen[i]) {
                missing = true;
                break;
            }
        }

        if(!missing) {
            int min_v = INF;
            for(int i = 0; i < K; i++) {
                if(A[i].second >= N - K + cnt - 1) {
                    min_v = std::min(min_v, A[i].first); 
                }
            }
            ans = (ans - min_v + MOD) % MOD;
            ans = (ans + A[K].first) % MOD;
        }
    } else {
        int cnt = 0;
        for(int i = K - 1; i >= 0; i--) {
            if(S[i] == '1') {
                cnt += 1;
            } else {
                break;
            }
        }

        std::vector<int> seen(N, 0);
        for(int i = 0; i < K; i++) {
            ans += A[i].first;
            ans %= MOD;
            seen[A[i].second] = 1;
        }

        bool missing = false;
        for(int i = 0; i < K - cnt + 1; i++) {
            if(!seen[i]) {
                missing = true;
                break;
            }
        }

        if(!missing) {
            int min_v = INF;
            for(int i = 0; i < K; i++) {
                if(A[i].second < K - cnt + 1) {
                    min_v = std::min(min_v, A[i].first); 
                }
            }
            ans = (ans - min_v + MOD) % MOD;
            ans = (ans + A[K].first) % MOD;
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
