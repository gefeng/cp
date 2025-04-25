#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 100;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> seen(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        seen[A[i]] = 1;
    }

    int ans = N;
    for(int c = 0; c <= MAX; c++) {
        if(!seen[c]) {
            continue;
        }

        int days = 0;
        for(int i = 0; i < N; ) {
            if(A[i] == c) {
                i += 1;
                continue;
            } 
            i += K;
            days += 1;
        }

        ans = std::min(ans, days);
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
