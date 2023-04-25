#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    LL ans = 0LL;
    std::vector<std::array<int, 3>> cnt1(N, {0, 0, 0});
    std::vector<std::array<int, 3>> cnt2(N, {0, 0, 0});

    for(int i = 0; i < N; i++) {
        if(i > 0) {
            cnt1[i] = cnt1[i - 1];
        }
        if(S[i] == 'R') {
            cnt1[i][0] += 1;
        } else if(S[i] == 'G') {
            cnt1[i][1] += 1;
        } else {
            cnt1[i][2] += 1;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        if(i < N - 1) {
            cnt2[i] = cnt2[i + 1];
        }
        if(S[i] == 'R') {
            cnt2[i][0] += 1;
        } else if(S[i] == 'G') {
            cnt2[i][1] += 1;
        } else {
            cnt2[i][2] += 1;
        }
    }

    for(int i = 1; i < N - 1; i++) {
        if(S[i] == 'R') {
            ans += 1LL * cnt1[i][1] * cnt2[i][2] + 1LL * cnt1[i][2] * cnt2[i][1];
        } else if(S[i] == 'G') {
            ans += 1LL * cnt1[i][0] * cnt2[i][2] + 1LL * cnt1[i][2] * cnt2[i][0];
        } else {
            ans += 1LL * cnt1[i][0] * cnt2[i][1] + 1LL * cnt1[i][1] * cnt2[i][0];
        }
    }

    for(int i = 1; i < N - 1; i++) {
        for(int j = i - 1, k = i + 1; j >= 0 && k < N; j--, k++) {
            if(S[j] != S[k] && S[j] != S[i] && S[k] != S[i]) {
                ans -= 1LL;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
