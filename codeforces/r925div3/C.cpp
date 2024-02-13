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

    int ans = N;
    int p = 0;
    while(p < N && A[p] == A[0]) {
        p += 1;
    }

    ans = std::min(ans, N - p);

    p = N - 1;
    while(p >= 0 && A[p] == A.back()) {
        p -= 1;
    }

    ans = std::min(ans, p + 1);

    if(A[0] == A.back()) {
        int l = 0;
        int r = N - 1;
        while(l < N && A[l] == A[0]) {
            l += 1;
        }

        while(r >= 0 && A[r] == A[0]) {
            r -= 1;
        }

        ans = std::min(ans, std::max(0, r - l + 1));
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
