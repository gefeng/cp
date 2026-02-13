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

    std::vector<std::pair<int, int>> ans;
    int now = 0;
    int pre = -1;
    for(int i = 0; i < N; i++) {
        if(pre == -1) {
            now += A[i];
            pre = i;
        } else if(now == 1) {
            if(A[i] == 1) {
                ans.emplace_back(pre, i);
            } else {
                ans.emplace_back(pre, pre);
                ans.emplace_back(i, i);
            }
            pre = -1;
            now = 0;
        } else if(now == -1) {
            if(A[i] == 1) {
                ans.emplace_back(pre, pre);
                ans.emplace_back(i, i);
            } else {
                ans.emplace_back(pre, i);
            }
            pre = -1;
            now = 0;
        }
    }

    if(now != 0) {
        std::cout << -1 << '\n';
        return;
    }

    int m = ans.size();
    std::cout << m << '\n';
    for(auto [l, r] : ans) {
        std::cout << l + 1 << ' ' << r + 1 << '\n';
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
