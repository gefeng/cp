#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int MAX = 100;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> cnt(MAX + 1, 0);
    for(int x : A) {
        cnt[x] += 1;
    }

    std::vector<int> ans(N, 1);

    int cnt_dup = 0;
    int a = -1;
    for(int i = 1; i <= MAX; i++) {
        if(cnt[i] > 1) {
            cnt_dup += 1;
            a = i;
        }
    }

    if(cnt_dup < 2) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> b(MAX + 1, 0);
    for(int i = 0; i < N; i++) {
        if(cnt[A[i]] > 1) {
            if(b[A[i]]) {
                ans[i] = A[i] == a ? 3 : 2;
            }
            b[A[i]] ^= 1;
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
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
