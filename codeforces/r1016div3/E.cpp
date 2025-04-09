#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int lo = 1;
    int hi = N;
    int ans = 0;

    while(lo <= hi) {
        int mid = (lo + hi) >> 1;
        
        std::set<int> s;
        int cnt_seg = 0;
        for(int i = 0; i < N; i++) {
            if(A[i] < mid) {
                s.insert(A[i]);
            }
            if(s.size() == mid) {
                cnt_seg += 1;
                s.clear();
            }
        }

        if(cnt_seg >= K) {
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
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
