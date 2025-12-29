#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if(M > N / 2) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = {A[i], i};
    }

    std::ranges::sort(a, [&](const auto& x, const auto& y) {
                return A[x.second] > A[y.second]; 
            });

    std::vector<std::pair<int, int>> ans;

    if(M == 0) {
        int h = 0;
        int p = -1;
        for(int i = 1; i < N; i++) {
            if(h < a[0].first) {
                h += a[i].first;
                p = i;
            } else {
                break;
            }
        }

        if(h < a[0].first) {
            std::cout << -1 << '\n';
            return;
        }

        while(a.size() > p + 1) {
            int n = a.size();
            ans.emplace_back(a[n - 1].second, a[n - 2].second);
            a.pop_back();
        }

        for(int i = 1; i <= p; i++) {
            ans.emplace_back(a[i].second, a[0].second);
        }
    } else {
        while(a.size() > M * 2) {
            int n = a.size();
            ans.emplace_back(a[n - 2].second, a[n - 1].second);
            a.pop_back();
        }

        int l = 0;
        int r = a.size() - 1;
        while(l < r) {
            ans.emplace_back(a[l].second, a[r].second);
            l += 1;
            r -= 1;
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
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
