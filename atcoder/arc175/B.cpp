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

    int cnt_open_flip = 0;
    int cnt_close_flip = 0;
    int bal = 0;
    for(int i = 0; i < N * 2; i++) {
        if(S[i] == '(') {
            bal += 1;
        } else {
            bal -= 1;
        }

        if(bal < 0) {
            cnt_close_flip += 1;
            bal += 2;
        }
    }

    cnt_open_flip += bal / 2;

    //std::cout << bal << ' ' << cnt_open_flip << ' ' << cnt_close_flip << '\n';

    int64_t ans = 0;
    if(2 * B > A) {
        int64_t d = std::min(cnt_open_flip, cnt_close_flip); 
        ans += d * A;
        ans += (cnt_open_flip + cnt_close_flip - d * 2) * B;
    } else {
        ans += (int64_t)(cnt_open_flip + cnt_close_flip) * B;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
