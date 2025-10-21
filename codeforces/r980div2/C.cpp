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

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a.first + a.second < b.first + b.second;
            }); 
    
    std::vector<int> ans;
    for(int i = 0; i < N; i++) {
        ans.push_back(A[i].first);
        ans.push_back(A[i].second);
    }

    for(int i = 0; i < N * 2; i++) {
        std::cout << ans[i] << " \n"[i == N * 2 - 1];
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
