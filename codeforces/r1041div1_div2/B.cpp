#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, X;
    std::cin >> N >> X;
    X -= 1;

    std::string S;
    std::cin >> S;

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '#') {
            cnt += 1;
        }
    }

    if(cnt == 0 || X == 0 || X == N - 1) {
        std::cout << 1 << '\n';
        return;
    }

    int l = -1;
    int r = N;
    for(int i = X - 1; i >= 0; i--) {
        if(S[i] == '#') {
            l = i;
            break;
        }
    }

    for(int i = X + 1; i < N; i++) {
        if(S[i] == '#') {
            r = i;
            break;
        }
    }

    int ans = 0;
    if(l == -1) {
        ans = std::min(X + 1, N - r + 1);
    } else if(r == N) {
        ans = std::min(l + 2, N - X);
    } else {
        ans = std::max(std::min(X + 1, N - r + 1), std::min(l + 2, N - X));
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
