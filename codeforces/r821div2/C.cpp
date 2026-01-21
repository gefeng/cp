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

    if(N == 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<std::pair<int, int>> ans;
    ans.emplace_back(0, N - 1);

    if(A[0] % 2 == 0) {
        for(int i = 1; i < N - 1; i++) {
            if(A[i] % 2 == 0) {
                ans.emplace_back(i, N - 1);
            } else {
                ans.emplace_back(0, i);
            }
        }
    } else {
        for(int i = 1; i < N - 1; i++) {
            if(A[i] % 2 == 0) {
                ans.emplace_back(0, i);
            } else {
                ans.emplace_back(i, N - 1);
            }
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(auto [i, j] : ans) {
        std::cout << i + 1 << ' ' << j + 1 << '\n';
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
