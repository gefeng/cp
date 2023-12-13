#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int S) {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int cnt = (N + 1) / 2 - 1;
    int64_t ans = 0;
    for(int i = 0; i < (N + 1) / 2; i++) {
        ans += A[i + N / 2 - cnt];
    }

    if(S == 0) {
        std::cout << ans << '\n';
        return;
    }

    std::reverse(A.begin(), A.end());
    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    for(int i = 0; i < N; i++) {
        int take = (i + 2) / 2;
        int64_t score = psum[i + 1] - psum[i - take + 1];
        ans = std::max(ans, score);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T, S;
    std::cin >> T >> S;
    while(T--) {
        run_case(S);
    }
}
