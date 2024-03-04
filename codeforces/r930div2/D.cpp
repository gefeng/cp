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
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int64_t> psum_l(N + 1, 0);
    std::vector<int64_t> psum_r(N + 1, 0);
    std::vector<int> cnt_l(N + 1, 0);
    std::vector<int> cnt_r(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        if(S[i - 1] == '>') {
            psum_l[i] = psum_l[i - 1];
            psum_r[i] = psum_r[i - 1] + i - 1;
            cnt_l[i] = cnt_l[i - 1];
            cnt_r[i] = cnt_r[i - 1] + 1;
        } else {
            psum_l[i] = psum_l[i - 1] + i - 1;
            psum_r[i] = psum_r[i - 1];
            cnt_l[i] = cnt_l[i - 1] + 1;
            cnt_r[i] = cnt_r[i - 1];
        }
    }

    auto nxt_l = [&](int st, int k) {
        if(k == 0) {
            return -1;
        }
        int lo = st;
        int hi = N - 1;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = cnt_l[mid + 1] - cnt_l[st];
            if(cnt >= k) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    auto pre_r = [&](int ed, int k) {
        if(k == 0) {
            return -1;
        }
        int lo = 0;
        int hi = ed;
        int res = -1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            int cnt = cnt_r[ed + 1] - cnt_r[mid];
            if(cnt >= k) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    };

    for(int i = 0; i < N; i++) {
        int64_t res = 0;
        if(S[i] == '>') {
            if(cnt_r[i + 1] > cnt_l[N] - cnt_l[i]) {
                // exit on the RHS
                int pre = pre_r(i - 1, cnt_l[N] - cnt_l[i]);
                if(pre == -1) {
                    res = N - i;
                } else {
                    res += 2 * (psum_l[N] - psum_l[i]);
                    res -= 2 * (psum_r[i] - psum_r[pre + 1]);
                    res += N - pre - pre - i; 
                }
            } else {
                // exit on the LHS
                int nxt = nxt_l(i + 1, cnt_r[i + 1]);
                res += 2 * (psum_l[nxt] - psum_l[i]);
                res -= 2 * psum_r[i];
                res += nxt + nxt + 1 - i; 
            }
        } else {
            if(cnt_r[i + 1] >= cnt_l[N] - cnt_l[i]) {
                // exit on the RHS    
                int pre = pre_r(i - 1, cnt_l[N] - cnt_l[i]);
                res += 2 * (psum_l[N] - psum_l[i + 1]);
                res -= 2 * (psum_r[i + 1] - psum_r[pre + 1]);
                res += i - pre + N - pre;
            } else {
                // exit on the LHS
                int nxt = nxt_l(i + 1, cnt_r[i + 1]);
                if(nxt == -1) {
                    res = i + 1;
                } else {
                    res += 2 * (psum_l[nxt] - psum_l[i + 1]);
                    res -= 2 * psum_r[i];
                    res += i + nxt + nxt + 1;
                }
            }
        }

        std::cout << res << " \n"[i == N - 1];
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
