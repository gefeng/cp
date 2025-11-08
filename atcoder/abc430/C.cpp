#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, A, B;
    std::cin >> N >> A >> B;

    std::string S;
    std::cin >> S;

    std::vector<int> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + S[i] - 'a';
    }

    int cnt_a = 0;
    int cnt_b = 0;
    int64_t ans = 0;
    for(int l = 0, r = 0; r < N; r++) {
        if(S[r] == 'a') {
            cnt_a += 1;
        } else {
            cnt_b += 1;
        }

        while(cnt_a > A) {
            if(S[l] == 'a') {
                cnt_a -= 1;
            } else {
                cnt_b -= 1;
            }
            l += 1;
        }
        while(cnt_a && S[l] != 'a') {
            cnt_b -= 1;
            l += 1;
        }

        if(cnt_a == A && cnt_b < B) {
            int d = B - cnt_b;
            int lo = 0;
            int hi = l - 1;
            int j = -1;
            while(lo <= hi) {
                int mid = (lo + hi) >> 1;
                if(psum[l] - psum[mid] >= d) {
                    lo = mid + 1;
                    j = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ans += l - j;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
