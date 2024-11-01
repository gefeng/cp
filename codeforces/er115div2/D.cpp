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
    
    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<int> freq_d(N + 1, 0);
    for(int i = 0; i < N; i++) {
        freq_d[A[i].second] += 1;
    }
    
    std::sort(A.begin(), A.end());
    
    int64_t ans = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i += 1; 
        }

        int len = i - j;
        if(len == 1) {
            continue; 
        }

        for(int k = j; k < i; k++) {
            auto [t, d] = A[k];
            int64_t cnt = int64_t(freq_d[d] - 1) * (len - 1);
            ans -= cnt;
        }
    }

    ans += int64_t(N) * (N - 1) * (N - 2) / 6;
    
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
