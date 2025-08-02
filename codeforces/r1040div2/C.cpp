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

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<int> removed(N, 0);
    for(int i = 0; i < N; i++) {
        auto [l, r] = A[i];
        for(int j = 0; j < N; j++) {
            if(i == j) {
                continue;
            }
            auto [x, y] = A[j];
            if(l >= x && r <= y) {
                removed[i] = 1;
            }
        }
    }

    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(!removed[i]) {
            ans.push_back(i);
        } 
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] + 1 << " \n"[i == size - 1];
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
