#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int l = 0;
    int r = N - 1;
    while(l < N && S[l] == '#') {
        l += 1;
    }

    while(r >= 0 && S[r] == '#') {
        r -= 1;
    }

    int max_v = *std::ranges::max_element(A.begin() + l, A.begin() + r + 1);

    std::pair<int, int> a{0, 0};
    std::pair<int, int> b{0, 0};
    int64_t ans = 0;
    for(int i = l; i <= r; ) {
        int j = i;
        int local_max = 0;
        int cnt = 0;
        while(i <= r && S[i] == S[j]) {
            if(A[i] > local_max) {
                local_max = A[i];
                cnt = 1;
            } else if(A[i] == local_max) {
                cnt += 1;
            }
            i += 1;
        }
        
        if(S[j] == '.') {
            if(local_max == max_v || a.first == max_v || b.first == max_v) {
                ans += static_cast<int64_t>(cnt) * a.second;
            }

            a = {local_max, cnt};
        } else {
            b = {local_max, cnt};
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
