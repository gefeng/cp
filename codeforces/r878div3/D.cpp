#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());
    
    int lo = 0;
    int hi = INF;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        int cnt = 0;
        for(int l = 0, r = 0; r < N; r++) {
            int t = 0;
            int sum = A[r] + A[l]; 
            if(sum % 2 == 0) {
                t = sum / 2 - A[l];
            } else {
                int x = sum / 2;
                int y = sum / 2 + 1;
                t = std::min(std::max(x - A[l], A[r] - x), std::max(y - A[l], A[r] - y));
            }
            if(t > mid) {
                l = r;
                r -= 1;
                cnt += 1;
                sum = 0LL;
            }
        }

        if(cnt < 3) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
