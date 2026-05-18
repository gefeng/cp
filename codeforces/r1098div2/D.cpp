#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A);

    std::vector<int> seen(N + 1, 0);
    std::vector<int> psum(N + 2, 0);
    std::vector<int> suffix_max(N + 1, 0);
    std::vector<int> suffix_min(N + 1, N + 1);

    for(auto [x, y] : A) {
        seen[y] = 1;
    }

    for(int i = 0; i <= N; i++) {
        psum[i + 1] = psum[i] + seen[i];
    }

    for(int i = 1; i <= N; i++) {
        suffix_max[i] = std::max(suffix_max[i - 1], A[N - i].second);
        suffix_min[i] = std::min(suffix_min[i - 1], A[N - i].second);
    }

    int64_t ans = 0;
    int prefix_min = N + 1;
    int prefix_max = 0;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            prefix_min = std::min(prefix_min, A[i].second);
            prefix_max = std::max(prefix_max, A[i].second);
            i++;
        }

        int l1 = prefix_min;
        int r1 = prefix_max;
        int l2 = suffix_min[N - i];
        int r2 = suffix_max[N - i];

        if(l1 < r1 && l2 < r2) {
            if(l1 > l2) {
                std::swap(l1, l2);
                std::swap(r1, r2);
            }
            if(r1 >= l2) {
                int l = std::max(l1 + 1, l2 + 1);
                int r = std::min(r1 - 1, r2 - 1);
                ans += psum[r + 1] - psum[l] + 1;
            }
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
