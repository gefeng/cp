#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].second--;
    }

    int M;
    std::cin >> M;
    std::vector<std::string> B(M);
    for(int i = 0; i < M; i++) {
        std::cin >> B[i];
    }

    std::set<std::tuple<int, int, int>> m;
    for(int i = 0; i < M; i++) {
        int n = B[i].size();
        for(int j = 0; j < n; j++) {
            m.emplace(n, j, B[i][j] - 'a');
        }
    }

    for(int i = 0; i < M; i++) {
        std::string& spine = B[i];    
        if(spine.size() != N) {
            std::cout << "No" << '\n';
            continue;
        }
        bool good = true;

        for(int j = 0; j < N; j++) {
            int c = spine[j] - 'a';
            auto [len, b] = A[j]; 
            std::tuple<int, int, int> k{len, b, c};
            auto it = m.find(k);
            if(it == m.end()) {
                good = false;
            }
        }

        std::cout << (good ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
