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

    std::vector<std::vector<int>> A(N);
    for(int i = 0; i < N; i++) {
        int K;
        std::cin >> K;

        A[i].resize(K, 0);
        for(int j = 0; j < K; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> pos(M + 1, -1);
    for(int i = 0; i < N; i++) {
        int size = A[i].size();
        for(int j = 0; j < size; j++) {
            if(pos[A[i][j]] == -1) {
                pos[A[i][j]] = i;
            } else {
                pos[A[i][j]] = N;
            }
        }
    }

    std::vector<int> take(N, 0);
    for(int i = 1; i <= M; i++) {
        if(pos[i] == -1) {
            std::cout << "No" << '\n';
            return;
        }
        if(pos[i] != N) {
            take[pos[i]] = 1;
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(!take[i]) {
            cnt += 1;
        }
    }

    if(cnt == 0 || cnt == 1) {
        std::cout << "No" << '\n';
        return;
    }

    std::cout << "Yes" << '\n';
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
