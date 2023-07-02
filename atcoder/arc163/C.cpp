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

    if(N == 1) {
        std::cout << "Yes" << '\n' << 1 << '\n';
        return;
    }

    if(N == 2) {
        std::cout << "No" << '\n';
        return;
    }

    auto f = [](int n) {
        std::vector<int> res;
        int x = 1;
        int y = 2;
        for(int i = 0; i < n - 1; i++) {
            res.push_back(x * y);
            x += 1;
            y += 1;
        }
        res.push_back(n);
        return res;
    };

    std::vector<int> ans = f(N);
    
    for(int i = 0; i < N - 1; i++) {
        if(ans[i] == ans[N - 1]) {
            std::vector<int> a = f(N - 1);
            ans[0] = 2;
            for(int j = 1; j < N; j++) {
                ans[j] = a[j - 1] * 2;
            }
            break;
        }
    }

    std::cout << "Yes" << '\n';
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
