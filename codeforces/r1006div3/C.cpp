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

    auto check = [&](int a) {
        for(int i = 0; i < 30; i++) {
            int b_1 = X & (1 << i) ? 1 : 0;
            int b_2 = a & (1 << i) ? 1 : 0;
            if(b_1 == 0 && b_2 == 1) {
                return false;
            }
        } 
        return true;
    };

    std::vector<int> ans(N, -1);
    int sum = 0;
    for(int i = 0; i < N; i++) {
        if(check(i)) {
            ans[i] = i;
            sum |= i;
        }
    }

    for(int i = 0; i < N; i++) {
        if(ans[i] == -1) {
            if(sum == X) {
                ans[i] = 0;
            } else {
                ans[i] = sum ^ X;
                sum = X;
            }
        }
    }

    if(sum != X) {
        int sum = 0;
        for(int i = 0; i < N - 1; i++) {
            sum |= ans[i];
        }
        ans.back() = sum ^ X;
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
