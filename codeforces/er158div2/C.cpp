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

    int min_v = (int)2e9;
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        min_v = std::min(min_v, A[i]);
        max_v = std::max(max_v, A[i]);
    }

    if(max_v == min_v) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> ans;
    while(min_v != max_v) {
        if(min_v % 2 == 0) {
            ans.push_back(2);
            max_v = (max_v + 2) / 2;
            min_v = (min_v + 2) / 2;
        } else {
            ans.push_back(1);
            max_v = (max_v + 1) / 2;
            min_v = (min_v + 1) / 2;
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    if(size <= N) {
        for(int i = 0; i < size; i++) {
            std::cout << ans[i] << " \n"[i == size - 1];
        }
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
