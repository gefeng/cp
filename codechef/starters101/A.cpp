#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, H;
    std::cin >> N >> H;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<int>());

    int lo = 0;
    int hi = (int)1e5;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int s = H;
        bool win = true;
        for(int i = 0; i < N; i++) {
            if(A[i] <= mid) {
                continue;
            }

            if(s <= A[i]) {
                win = false;
                break;
            }

            s -= A[i];
        }

        if(win) {
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
