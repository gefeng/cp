#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t X;
    std::cin >> N >> X;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    std::vector<int64_t> days(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + A[i];
    }

    for(int i = 0; i < N; i++) {
        days[i + 1] = days[i] + int64_t(1 + A[i]) * A[i] / 2;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int64_t tot = psum[i + 1];
        if(tot < X) {
            int lo = i + 1;
            int hi = N - 1;
            int j = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(psum[N] - psum[mid] + tot < X) {
                    j = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
            int64_t cnt = 0;
            if(j == -1) {
                cnt = days[i + 1];
                int64_t left = X - tot;
                cnt += (A.back() - left + 1 + A.back()) * left / 2;
            } else {
                cnt = days[i + 1] + days[N] - days[j];
                int64_t left = X - tot - (psum[N] - psum[j]);
                j -= 1;
                cnt += (A[j] - left + 1 + A[j]) * left / 2;
            }
            ans = std::max(ans, cnt);
        } else {
            int lo = 0;
            int hi = i;
            int j = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(psum[i + 1] - psum[mid] < X) {
                    j = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            int64_t cnt = 0;
            if(j == -1) {
                cnt = (A[i] - X + 1 + A[i]) * X / 2;
            } else {
                cnt = days[i + 1] - days[j];
                int64_t left = X - (psum[i + 1] - psum[j]);
                if(left) {
                    j -= 1;
                    cnt += (A[j] - left + 1 + A[j]) * left / 2;
                }
            }
            ans = std::max(ans, cnt);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
