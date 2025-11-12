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
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::pair<int, int>> A(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    auto query = [&](int l, int r) {
        std::cout << "? " << l + 1 << ' ' << r + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::ranges::sort(A);

    std::vector<std::pair<int, int>> a;
    int max_v = -1;
    for(int i = 0; i < Q; ) {
        int j = i;
        int max_r = 0;
        while(i < Q && A[j].first == A[i].first) {
            max_r = std::max(max_r, A[i].second);
            i += 1;
        }
        if(max_r <= max_v) {
            continue;            
        }
        max_v = std::max(max_v, max_r);
        a.emplace_back(A[j].first, max_r);
    }

    int n = a.size();
    int ans = 0;
    int lo = 0;
    int hi = n - 1;
    int p = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        auto [l, r] = a[mid];
        int prefix_min = query(l, N - 1);
        int suffix_min = query(0, r);

        if(prefix_min >= suffix_min) {
            p = mid; 
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    for(int i = 0; i < 2 && p + i < n; i++) {
        ans = std::max(ans, query(a[p + i].first, a[p + i].second));
    }

    std::cout << "! " << ans << std::endl;
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
