#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case(int T) {
    int64_t A, B, C;
    std::cin >> A >> B >> C;

    int64_t lo = 0;
    int64_t hi = 1e17;
    int64_t ans = 0;

    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        std::array<int64_t, 3> need = {mid + 1, mid, mid};

        bool ok = true;
        if(B <= A) {
            int64_t cnt = C / B;
            ok = cnt * 2 >= need[0] && cnt * 2 >= need[1] && cnt * 2 >= need[2];
        } else {
            if(A * 2 <= B) {
                int64_t cnt = C / A;
                int64_t rem = C % A;
                std::array<int64_t, 3> have = {cnt * 2 + rem / B * 2, cnt + rem / B * 2, cnt + rem / B * 2};
                for(int i = 0; i < 3; i++) {
                    ok = ok && have[i] >= need[i];
                }
            } else {
                int64_t cnt = C / B;
                int64_t rem = C % B;
                if(cnt * 2 < need[1]) {
                    std::array<int64_t, 3> have = {cnt * 2 + rem / A * 2, cnt * 2 + rem / A, cnt * 2 + rem / A}; 
                    for(int i = 0; i < 3; i++) {
                        ok = ok && have[i] >= need[i];
                    } 
                } else {
                    if(cnt * 2 >= need[0]) {
                        ok = true;
                    } else {
                        if(rem / A > 0 || (cnt && (rem + B) / A > 1)) {
                            ok = true;
                        } else {
                            ok = false;
                        }
                    }
                }
            }
        }

        if(ok) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
