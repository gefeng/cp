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
    
    int ans = 0;
    
    std::vector<int> now(A);
    for(int x = 1; x <= N; x++) {
        std::vector<int> nxt;
        for(int i = 0; i < N - x; i++) {
            if(now[i] == x) {
                ans += std::min(i, N - x - i);
            } else {
                nxt.push_back(now[i]);
            }
        }
        now = std::move(nxt);
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
