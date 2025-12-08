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

    auto query = [](int x, int y) {
        std::cout << "? " << x + 1 << ' ' << y + 1 << std::endl;
        int U, V;
        std::cin >> U >> V;
        return std::pair<int, int>(U - 1, V - 1);
    };

    std::vector<int> pos(N + 1, 0);
    for(int i = 0; i < N; i++) {
        pos[A[i]] = i;
    }

    auto swap = [&](int i, int j) {
        int x = A[i];
        int y = A[j];
        std::swap(A[i], A[j]);
        pos[x] = j;
        pos[y] = i;
    };

    int x = 1;
    int y = N;
    while(x <= N / 2) {
        while(pos[x] != x - 1 || pos[y] != y - 1) {
            int p1 = pos[x];
            int p2 = pos[y];

            if(p2 < p1 && p2 == N - 1 - p1) {
                query(p1, p2);
                swap(p1, p2);
            }

            p1 = pos[x];
            if(p1 != x - 1) {
                auto [i, j] = query(p1, x - 1);
                swap(i, j);
            }
            p2 = pos[y];
            if(p2 != y - 1) {
                auto [k, s] = query(p2, y - 1);
                swap(k, s);
            }
        }
        x += 1;
        y -= 1;
    }

    std::cout << "! " << std::endl;
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
