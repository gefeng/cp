#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    LL ans = 0LL;
    for(int l = 0, r = 0; r <= N; r++) {
        if(r == N || A[r] > Q) {
            int len = r - l;
            if(len >= K) {
                ans += 1LL * (1 + len - K + 1) * (len - K + 1) / 2LL;
            }
            l = r + 1;
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
