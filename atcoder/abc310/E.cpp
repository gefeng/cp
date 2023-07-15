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

    int64_t cnt0 = 0;
    int64_t cnt1 = 0;
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            cnt0 = 1;
            cnt1 = i;
            ans += cnt1;
        } else {
            int tmp = cnt0;
            cnt0 = cnt1;
            cnt1 = tmp + 1;
            ans += cnt1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
