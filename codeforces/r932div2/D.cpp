#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> a(2, std::vector<int>());
    for(int i = 0; i < N; i++) {
        a[A[i] % 2].push_back(A[i]);
    } 

    int64_t ans = (int64_t)(C + 1) * (C + 2) / 2;
    for(int i = 0; i < N; i++) {
        ans -= (A[i] / 2 + 1) + (C - A[i] + 1);
    }

    int64_t cnt = 0;
    for(int r = 0; r < 2; r++) {
        std::array<int, 2> cnt_rem = {};
        for(int x : a[r]) {
            cnt_rem[x % 2] += 1;
            cnt += cnt_rem[x % 2]; 
        }
    }

    ans += cnt;
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
