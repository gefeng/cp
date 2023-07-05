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
    int N, C, D;
    std::cin >> N >> C >> D;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    LL ans = 1LL * C * N + D;
    

    sort(A.begin(), A.end());
    A.erase(std::unique(A.begin(), A.end()), A.end());    

    LL remove = 1LL * (N - A.size()) * C;

    N = A.size();
    
    std::vector<LL> keep(N, 0LL);
    int pre = 0;
    for(int i = 0; i < N; i++) {
        int d = A[i] - pre - 1;
        LL cost = 1LL * d * D;

        keep[i] = i == 0 ? cost : keep[i - 1] + cost;
        pre = A[i];
    }

    for(int i = 0; i < N; i++) {
        ans = std::min(ans, remove + keep[i] + 1LL * C * (N - i - 1)); 
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
