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

    std::vector<int> d;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        ans += abs(A[i] - A[i - 1]);
        d.push_back(abs(A[i] - A[i - 1]));
    }

    std::sort(d.begin(), d.end(), std::greater<int>());
    
    for(int i = 0; i < K - 1; i++) {
        ans -= d[i];
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
