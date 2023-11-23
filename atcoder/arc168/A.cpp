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

    int64_t ans = 0;
    for(int i = 0; i < N - 1; ) {
        if(S[i] == '>') {
            int j = i;
            while(i < N - 1 && S[i] == S[j]) {
                i += 1;
            }
            int64_t cnt = i - j;
            ans += cnt * (cnt + 1) / 2;
        } else {
            i += 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
