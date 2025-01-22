#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    std::vector<int> have(N * M, -1);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            have[A[i][j]] = i;
        }
    }

    std::vector<int> p(N, -1);
    for(int i = 0; i < N; i++) {
        if(p[i] != -1) {
            std::cout << -1 << '\n';
            return;
        }
        p[i] = have[i];
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int card = i * N + j;
            int who = p[j];
            if(have[card] != who) {
                std::cout << -1 << '\n';
                return;
            }
        }
    } 

    for(int i = 0; i < N; i++) {
        std::cout << p[i] + 1 << " \n"[i == N - 1];
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
