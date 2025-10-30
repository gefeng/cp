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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> a(A);
    std::ranges::sort(a);

    auto count = [](int t, int x) {
        int d = std::abs(t - x) - 1;
        int cnt = 0;
        if(t < x) {
            cnt = d / 2;
        } else {
            cnt = (d + 1) / 2;
        }
        return cnt;
    };
 
    for(int i = 0; i < N; i++) {
        auto it = std::upper_bound(a.begin(), a.end(), A[i]);
        if(it == a.end()) {
            std::cout << -1 << " \n"[i == N - 1];
            continue;
        }

        int r = *it;
        it = std::lower_bound(a.begin(), a.end(), A[i]);
        if(it == a.begin()) {
            std::cout << -1 << " \n"[i == N - 1];
            continue;
        }

        int l = *std::prev(it);

        int res = count(l, A[i]) + count(r, A[i]) + 1;
        std::cout << res << " \n"[i == N - 1];
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
