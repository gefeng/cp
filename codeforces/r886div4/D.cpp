#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int ans = 1;
    int cnt = 1;
    for(int i = 1; i < N; i++) {
        if(A[i] - A[i - 1] > K) {
            cnt = 1;
        } else {
            cnt += 1;
        }

        ans = std::max(ans, cnt);
    }

    std::cout << N - ans << '\n';
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
