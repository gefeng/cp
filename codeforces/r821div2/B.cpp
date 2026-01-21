#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X, Y;
    std::cin >> N >> X >> Y;

    if(X > Y) {
        std::swap(X, Y);
    }

    if(X > 0) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N - 1, -1);
    int cnt = 0;
    
    for(int i = 0, j = 0; i < N - 1; i++) {
        if(j > N - 1) {
            std::cout << -1 << '\n';
            return;
        }
        ans[i] = j;

        if(++cnt == Y) {
            cnt = 0;
            j = i + 2;
        }
    }

    if(cnt) {
        std::cout << -1 << '\n';
        return;
    }

    for(int i = 0; i < N - 1; i++) {
        std::cout << ans[i] + 1 << " \n"[i == N - 2];
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
