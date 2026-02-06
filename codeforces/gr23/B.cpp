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

    int ans = 0;
    int l = 0;
    int r = N - 1;
    while(l <= r) {
        while(l <= r && A[l] == 0) {
            l += 1;
        }
        while(l <= r && A[r] == 1) {
            r -= 1;
        }

        if(l < r) {
            std::swap(A[l], A[r]);
            ans += 1;
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
