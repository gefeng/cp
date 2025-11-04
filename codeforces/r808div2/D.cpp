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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> now;
    int c0 = std::ranges::count(A, 0);
    for(int i = c0; i < N; i++) {
        now.push_back(A[i]);
    }

    while(now.size() > 1) {
        std::vector<int> nxt;
        int size = now.size();
        int nc0 = 0;
        for(int i = 1; i < size; i++) {
            int x = now[i] - now[i - 1];
            if(x > 0) {
                nxt.push_back(x);
            } else {
                nc0 += 1;
            }
        }

        if(c0) {
            nxt.push_back(now[0]);
            c0 -= 1;
        }
        c0 += nc0;

        std::ranges::sort(nxt);
        now = std::move(nxt);
    }

    int ans = now.empty() ? 0 : now[0];

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
