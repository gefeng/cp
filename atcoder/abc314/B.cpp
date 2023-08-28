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

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        A[i].resize(M);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int X;
    std::cin >> X;

    std::vector<std::pair<int, int>> a;
    for(int i = 0; i < N; i++) {
        int m = A[i].size();
        for(int j = 0; j < m; j++) {
            if(A[i][j] == X) {
                a.emplace_back(m, i + 1);
                break;
            }
        }
    }

    std::sort(a.begin(), a.end());
    
    std::vector<int> ans;
    for(auto p : a) {
        if(p.first == a.front().first) {
            ans.push_back(p.second);
        }
    }

    int k = ans.size();
    std::cout << k << '\n';
    for(int i = 0; i < k; i++) {
        std::cout << ans[i] << " \n"[i == k - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
