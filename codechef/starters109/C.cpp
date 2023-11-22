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

    std::vector<int> eve;
    std::vector<int> odd;
    
    for(int x : A) {
        if(x % 2 == 0) {
            eve.push_back(x);
        } else {
            odd.push_back(x);
        }
    }

    std::sort(eve.begin(), eve.end(), std::greater<int>());
    std::sort(odd.begin(), odd.end(), std::greater<int>());
    if(eve.size() % 2 == 1) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> ans(N);
    int p = 0;
    auto solve = [&](std::vector<int>& a) {
        int n = a.size();
        for(int i = 0; i < n / 2; i++) {
            int x = (a[i] + a[i + n / 2]) / 2;
            int y = a[i] - x;
            ans[p] = x;
            ans[p + N / 2] = y;
            p += 1;
        }
    };

    solve(eve);
    solve(odd);

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
