#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::vector<int>> A(M);
    std::vector<char> B(M);
    for(int i = 0; i < M; i++) {
        int C;
        std::cin >> C;
        A[i].resize(C, 0);
        for(int j = 0; j < C; j++) {
            std::cin >> A[i][j];
            A[i][j] -= 1;
        }
        std::cin >> B[i];
    }

    int ans = 0;
    for(int mask = 0; mask < (1 << N); mask++) {
        bool valid = true;
        for(int i = 0; i < M; i++) {
            int cnt = 0;
            for(int k : A[i]) {
                if(mask & (1 << k)) {
                    cnt += 1; 
                }
            }
            
            bool opened = B[i] == 'o';
            bool res = cnt >= K;
            if(res != opened) {
                valid = false;
                break;
            }
        }

        if(valid) {
            ans += 1;
        }
    } 

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
