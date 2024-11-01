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

    std::sort(A.begin(), A.end());
    
    N = A.size();
    
    int ans = N - 2;
    for(int i = 0; i < N - 2; i++) {
        auto it = std::upper_bound(A.begin() + i + 1, A.begin() + N - 1, A.back() - A[i]);
        int cnt = it - A.begin() - i - 1 + i;
        ans = std::min(ans, cnt);

        it = std::lower_bound(A.begin() + i + 2, A.end(), A[i] + A[i + 1]);
        cnt = A.end() - it + i;
        ans = std::min(ans, cnt);
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
