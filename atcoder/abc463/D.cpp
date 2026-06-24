#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = static_cast<int>(1e9);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.second < y.second;
            });

    int ans = -1;
    int lo = 0;
    int hi = MAX;

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int now = A[0].second;
        int k = 1;
        for(int i = 1; i < N; i++) {
            if(A[i].first > now && A[i].first - now >= mid) {
                if(++k == K) {
                    break;
                }
                now = A[i].second;
            }
        }
        if(k == K) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
