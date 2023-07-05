#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<int> digits(N, -1);
    for(int i = 0; i < M; i++) {
        int p = A[i].first - 1;
        int v = A[i].second;

        if(digits[p] == -1) {
            digits[p] = v;
        } else {
            if(digits[p] != v) {
                std::cout << -1 << '\n';
                return;
            }
        }
    }

    if(N > 1 && digits[0] == 0) {
        std::cout << -1 << '\n';
        return;
    }

    if(N == 1) {
        std::cout << (digits[0] == -1 ? 0 : digits[0]) << '\n';
        return;
    }

    int ans = 0;
    bool set = false;
    for(int d : digits) {
        if(d == -1) {
            if(!set) {
                ans = ans * 10 + 1;
                set = true;
            } else {
                ans = ans * 10;
            }
        } else {
            ans = ans * 10 + d;
            set = true;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
