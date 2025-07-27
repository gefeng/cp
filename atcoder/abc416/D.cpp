#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<int> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::ranges::sort(A);
    std::map<int, int> m;
    for(int x : B) {
        m[x] += 1;
    }

    int64_t ans = 0;
    std::vector<int> used(N, 0);
    for(int i = 0; i < N; i++) {
        auto it = m.lower_bound(M - A[i]);
        if(it != m.end()) {
            used[i] = 1;
            ans += A[i] + it->first - M;
            if(--(it->second) == 0) {
                m.erase(it);
            }
        } else {
            ans += A[i];
        }
    }

    for(auto [x, f] : m) {
        ans += static_cast<int64_t>(x) * f;
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
