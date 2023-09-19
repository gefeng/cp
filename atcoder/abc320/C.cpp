#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int M;
    std::cin >> M;

    std::vector<std::string> A(3);
    for(int i = 0; i < 3; i++) {
        std::cin >> A[i];
    }

    int ans = INF;
    for(int i = 0; i < M; i++) {
        char c = A[0][i];
        
        std::vector<int> a;
        std::vector<int> b;
        for(int j = 0; j < M; j++) {
            if(A[1][j] == c) {
                a.push_back(j);
            } 

            if(A[2][j] == c) {
                b.push_back(j);
            }
        }

        if(a.empty() || b.empty()) {
            continue;
        }

        for(int x : a) {
            for(int y : b) {
                std::vector<int> t = {i, x, y};
                std::sort(t.begin(), t.end());
                
                int need = 0;
                if(t.front() == t.back()) {
                    need = 2 * M + i; 
                } else if(t[0] == t[1]) {
                    need = M + i;
                } else if(t[1] == t[2]) {
                    need = M + t[1]; 
                } else {
                    need = t[2];
                }

                ans = std::min(ans, need);
            }
        }
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
