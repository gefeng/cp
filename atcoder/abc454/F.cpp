#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> a;
    std::vector<int> b;
    for(int i = 0; i < N / 2; i++) {
        a.push_back((A[i] - A[N - 1 - i] + M) % M);
    }

    int n = a.size();
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            b.push_back((a[i] + M) % M);
        } else {
            b.push_back((a[i] - a[i - 1] + M) % M);
        }
    }
    b.push_back(M - a.back());
    
    std::ranges::sort(b);

    n = b.size();
    std::vector<int64_t> suffix(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        suffix[i] = suffix[i - 1] + M - b[n - i];
    }

    int64_t prefix = 0;
    int64_t ans = suffix[n];
    for(int i = 1; i <= n; i++) {
        prefix += b[i - 1];
        ans = std::min(ans, std::max(prefix, suffix[n - i])); 
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
