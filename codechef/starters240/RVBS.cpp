#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;

    int64_t ans = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    std::vector<int> pos;
    for(int i = 0; i < N; i++) {
        cnt1 += S[i] - '0';
        cnt2 += T[i] - '0';
        if(S[i] == '1') {
            pos.push_back(i);
        }
    }

    if(cnt1 != cnt2) {
        std::cout << -1 << '\n';
        return;
    }

    int i = 0;
    int j = 0;
    while(i < N && j < N) {
        while(i < N && S[i] == '0') {
            i++;
        }
        while(j < N && T[j] == '0') {
            j++;
        }

        if(i < N && j < N) {
            if(i != j) {
                ans++;
            }
            i++;
            j++;
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
