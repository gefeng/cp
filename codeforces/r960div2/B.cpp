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
    Y -= 1;
    X -= 1;

    std::vector<int> ans(N, -1);
    for(int i = Y; i <= X; i++) {
        ans[i] = 1;
    }
    
    for(int i = Y - 2, j = 0; i >= 0; i--, j ^= 1) {
        ans[i] = j == 0 ? 1 : -1;
    }

    for(int i = X + 2, j = 0; i < N; i++, j ^= 1) {
        ans[i] = j == 0 ? 1 : -1;
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
