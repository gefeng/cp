#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, D;
    std::cin >> N >> D;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto in_range = [](int x1, int y1, int x2, int y2, int d) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= d * d;
    };

    std::vector<int> infected(N, 0);
    std::vector<int> cur;
    cur.push_back(0);
    infected[0] = true;
    while(!cur.empty()) {
        std::vector<int> nxt;
        for(int x : cur) {
            for(int i = 0; i < N; i++) {
                if(!infected[i] && in_range(A[x].first, A[x].second, A[i].first, A[i].second, D)) {
                    nxt.push_back(i); 
                    infected[i] = true;
                }
            }
        }

        std::swap(cur, nxt);
    }

    for(int i = 0; i < N; i++) {
        std::cout << (infected[i] ? "Yes" : "No") << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
