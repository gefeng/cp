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
    
    std::vector<std::string> A(N);
    std::vector<std::pair<int, int>> res(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        res[i].second = i;
        for(int j = 0; j < N; j++) {
            if(A[i][j] == 'o') {
                res[i].first += 1;
            }
        }
    }

    std::sort(res.begin(), res.end(), [](const auto& a, const auto& b) {
                if(a.first == b.first) {
                    return a.second < b.second;
                }
                return a.first > b.first;
            });

    for(int i = 0; i < N; i++) {
        std::cout << res[i].second + 1 << " \n"[i == N - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
