#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt = std::ranges::count(A, 1);
    std::vector<int> ans;
    if(cnt <= N / 2) {
        for(int i = 0; i < N; i++) {
            if(A[i] == 0) {
                ans.push_back(A[i]);
            }
        } 
    } else {
        for(int i = 0; i < N; i++) {
            if(A[i]) {
                ans.push_back(A[i]);
            }
        }
        if(ans.size() % 2 == 1) {
            ans.pop_back();
        }
    }

    int size = ans.size();
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i] << " \n"[i == size - 1];
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
