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
    int pre = N;
    int swapped = 0;
    int have_b = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'A') {
            if(have_b) {
                ans += swapped ? pre - i : pre - i - 1;
                swapped = 1;
            }
            pre = i;
        } else {
            have_b = 1;
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
