#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::array<int, 3>> A(M);
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 2; j++) {
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
        char C;
        std::cin >> C;
        A[i][2] = C == 'B' ? 1 : 0;
    }

    std::vector<std::pair<int, int>> black;
    std::vector<std::pair<int, int>> white;
    for(int i = 0; i < M; i++) {
        if(A[i][2] == 1) {
            black.emplace_back(A[i][0], A[i][1]);
        } else {
            white.emplace_back(A[i][0], A[i][1]);
        }
    }

    std::sort(black.begin(), black.end());
    std::sort(white.begin(), white.end());

    int n = black.size();
    int m = white.size();
    int p = 0;
    int min_white = N + N;
    for(int i = 0; i < n; ) {
        int j = i;
        int max_c = -1;
        while(i < n && black[i].first == black[j].first) {
            max_c = std::max(max_c, black[i++].second);
        }
        
        while(p < m && white[p].first <= black[j].first) {
            min_white = std::min(min_white, white[p++].second);
        }

        if(min_white <= max_c) {
            std::cout << "No" << '\n';
            return;
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
