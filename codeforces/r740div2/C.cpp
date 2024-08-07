#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = int(1e9) + 10;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;

        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; i++) {
        int lo = 1;
        int hi = MAX;
        int res = -1;
        int k = A[i].size();
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            
            bool ok = true;
            int p = mid;
            for(int j = 0; j < k; j++) {
                if(p <= A[i][j]) {
                    ok = false;
                    break;
                }
                p += 1;
            }
            if(ok) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        a.emplace_back(res, k);
    }

    std::sort(a.begin(), a.end());

    int ans = 0;
    int now = 0;
    for(int i = 0; i < N; i++) {
        if(now < a[i].first) {
            ans += a[i].first - now;
            now = a[i].first;
        }
        now += a[i].second;
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
