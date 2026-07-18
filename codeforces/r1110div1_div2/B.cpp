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

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        A[i] -= C;
    }

    std::ranges::sort(A);

    int l = 0;
    int r = N - 1;
    while(l <= r) {
        if(A[l] >= 0 || l == r) {
            for(int i = l; i <= r; i++) {
                ans += A[i];
            }
            break;
        }

        ans += A[r];
        l++;
        r--;
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
