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

    std::vector<int> A(X);
    for(int i = 0; i < X; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end());

    int ans = 0;
    int tot = X;
    std::vector<std::pair<int, int>> good;
    std::vector<int> vis(X, 0);
    for(int i = 0; i < X; i++) {
        int j = (i + 1) % X;
        int d = (A[j] - A[i] + N) % N;
        if(d == 1) {
            continue;
        }

        if(d == 2) {
            ans += 1;
            continue;
        }

        int x = d - 1;
        int add = std::min(Y, x / 2);
        
        if(x - add * 2 == 1) {
            good.emplace_back(add, i);
        }
    }

    std::sort(good.begin(), good.end());
    for(auto [v, i] : good) {
        if(Y >= v) {
            ans += v + 1;
            tot += v;
            Y -= v;
            vis[i] = 1;
        }
    }

    for(int i = 0; i < X; i++) {
        int j = (i + 1) % X;
        int d = (A[j] - A[i] + N) % N;
        if(d > 2 && Y && !vis[i]) {
            int x = d - 1;
            int add = std::min(Y, x / 2);
            ans += add;
            Y -= add;
            tot += add;
        }
    }

    ans += tot - 2;

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
