#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, W;
    std::cin >> N >> W;

    std::vector<std::vector<std::pair<int, int>>> A(W);
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        X -= 1;
        Y -= 1;
        A[X].emplace_back(Y, i); 
    } 

    for(int i = 0; i < W; i++) {
        std::sort(A[i].begin(), A[i].end(), std::greater<std::pair<int, int>>());
    }

    std::vector<int> time(N, -1);
    while(true) {
        bool end = false;
        int max_t = 0;
        std::vector<int> removed;
        for(int i = 0; i < W; i++) {
            if(A[i].empty()) {
                end = true;
                break;
            }
            auto [r, idx] = A[i].back();
            A[i].pop_back();
            max_t = std::max(max_t, r);
            removed.push_back(idx);
        }

        if(end) {
            break;
        }
        
        for(int i : removed) {
            time[i] = max_t;
        }
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T, X;
        std::cin >> T >> X;
        T -= 1;
        X -= 1;
        
        std::cout << (time[X] == -1 || time[X] > T ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
