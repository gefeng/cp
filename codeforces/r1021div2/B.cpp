#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int64_t ans = 0;
    std::map<int, int> diff;
    for(int i = 0; i < N; i++) {
        int d = std::min(i, N - i - 1);         
        if(d * 2 + 1 >= N - K) {
            diff[A[i]] += 1;
            diff[A[i] + 1] -= 1;
        }
    }

    for(int i = 0; i < N; i++) {
        int lo = i + 1;
        int hi = N - 1;
        int j = -1;

        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = std::min(i + 1, N - mid);
            if(cnt * 2 >= N - K) {
                j = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(j == -1) {
            continue;
        }

        int l = A[i];
        int r = A[j];

        diff[l] += 1;
        diff[r + 1] -= 1;
    }

    int rolling = 0;
    int pre = -1;
    for(auto [x, cnt] : diff) {
        rolling += cnt;
        if(rolling == 0) {
            ans += x - pre;
            pre = -1;
        } else {
            pre = pre == -1 ? x : pre;
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
