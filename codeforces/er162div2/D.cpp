#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    std::vector<int64_t> ssum(N + 1, 0);
    std::vector<int> l(N, -1);
    std::vector<int> r(N, N);
    for(int i = 1; i <= N; i++) {
        psum[i] = psum[i - 1] + A[i - 1];
        ssum[i] = ssum[i - 1] + A[N - i];
    }

    for(int i = N - 2; i >= 0; i--) {
        r[i] = A[i] != A[i + 1] ? i + 1 : r[i + 1];
    }
    
    for(int i = 1; i < N; i++) {
        l[i] = A[i] != A[i - 1] ? i - 1 : l[i - 1];
    }

    std::vector<int> ans(N, -1);
    for(int i = 1; i < N; i++) {
        if(A[i - 1] > A[i]) {
            ans[i] = 1;
        } else {
            int lo = 0;
            int hi = i - 1;
            int res = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                int64_t sum = psum[i] - psum[mid];
                if(sum > A[i] && r[mid] < i) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if(res != -1) {
                ans[i] = i - res;
            }
        }
    }

    for(int i = N - 2; i >= 0; i--) {
        if(A[i + 1] > A[i]) {
            ans[i] = 1;
        } else {
            int lo = i + 1;
            int hi = N - 1;
            int res = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                int64_t sum = ssum[N - 1 - i] - ssum[N - 1 - mid];
                if(sum > A[i] && l[mid] > i) {
                    res = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            if(res != -1) {
                ans[i] = ans[i] == -1 ? res - i : std::min(ans[i], res - i); 
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
