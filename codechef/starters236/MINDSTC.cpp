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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);
    
    int tot = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[j] == A[i]) {
            i++;
        }
        tot++;
    }

    std::vector<int> dp(N + 1, tot);
    std::vector<int> freq(N + 10, 0);

    for(int i = N - 1; i >= 0; ) {
        int j = i;
        while(i >= 0 && A[j] == A[i]) {
            i--;
        }

        int cnt = tot;
        if(freq[A[j] + 2] != 0) {
            cnt--;
        }
        if(freq[A[j] + 1] != 0 && freq[A[j] + 3] != 0) {
            cnt--;
        }
        dp[A[j]] = std::min(dp[A[j]], cnt);

        freq[A[j]] = j - i;
    }

    for(int i = N - 1; i > 0; i--) {
        dp[i] = std::min(dp[i], dp[i + 1]);
    }

    for(int i = 1; i <= N; i++) {
        std::cout << dp[i] << " \n"[i == N];
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
