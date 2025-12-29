#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t query(int l, int r) {
    std::cout << "? " << l + 1 << ' ' << r + 1 << std::endl;
    int64_t Q;
    std::cin >> Q;
    return Q;
}

void dfs(int l, int r, int64_t sum, int64_t& ans) {
    if(l == r) {
        ans = std::max(ans, sum);
        return;
    }

    int lo = l;
    int hi = r;
    int p = -1;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        int64_t q = query(l, mid);
        if(q == sum / 2) {
            p = mid;
            break;
        }
        if(q < sum / 2) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if(p - l <= r - p - 1) {
        dfs(l, p, sum / 2, ans);
    } else {
        dfs(p + 1, r, sum / 2, ans);
    }
}

void run_case() {
    int N;
    std::cin >> N;

    int64_t sum = query(0, N - 1);
    int64_t ans = 0;
    dfs(0, N - 1, sum, ans); 

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
