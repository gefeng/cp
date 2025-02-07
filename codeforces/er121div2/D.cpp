#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);
constexpr int LOG = 20;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i] == A[j]) {
            i += 1;
        }
        a.emplace_back(A[j], i - j);
    }

    int n = a.size();
    std::vector<int> psum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        psum[i + 1] = psum[i] + a[i].second;
    }

    auto find = [](int x) {
        int p_2 = 1;
        while(p_2 < x) {
            p_2 *= 2;
        }
        return p_2;
    };
    
    auto bs = [&](int st, int t) {
        int lo = st;
        int hi = n - 1;
        int res = n;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int len = psum[mid + 1] - psum[st];
            if(len > t) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
            
        }
        return res;
    };

    int ans = INF;
    int prefix = 0;
    for(int i = 0; i < n; i++) {
        auto [_, f] = a[i];
        prefix += f;
        
        int extra = find(prefix) - prefix;
        
        int p_2 = 1;
        for(int j = 0; j <= LOG; j++, p_2 *= 2) {
            int k = bs(i + 1, p_2) - 1;
            int mid = psum[k + 1] - psum[i + 1];
            int suffix = psum[n] - psum[k + 1];

            ans = std::min(ans, extra + p_2 - mid + find(suffix) - suffix);
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
