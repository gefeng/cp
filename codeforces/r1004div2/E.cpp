#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;
    if(A[0] == 0) {
        ans += 1;
        for(int i = 0; i < N; i++) {
            if(A[i]) {
                ans += 1;
            }
        }
        std::cout << ans << '\n';
        return;
    }

    std::vector<int> prefix_min(N, INF);
    std::vector<int> good(N, 0);
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            prefix_min[i] = i == 0 ? A[i] : std::min(prefix_min[i - 1], A[i]);
        } else {
            prefix_min[i] = prefix_min[i - 1];
        }
    }

    int mex = 1;
    std::set<int> s;
    for(int i = N - 1; i >= 0; i--) {
        if(A[i]) {
            good[i] = prefix_min[i] >= mex ? 1 : 0;

            s.insert(A[i]);
            while(s.find(mex) != s.end()) {
                mex += 1;
            }
        }
    }

    std::vector<int> psum_good(N + 1, 0);
    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum_good[i + 1] = psum_good[i] + good[i];
        psum[i + 1] = psum[i] + (A[i] ? 1 : 0);
    }

    bool zero = false;
    for(int i = 0; i < N; i++) {
        if(A[i]) {
            ans += 1;
        } else {
            if(psum_good[i] == psum[i]) {
                zero = true;
            }
        }
    }
    
    ans += zero ? 1 : 0;
    
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
