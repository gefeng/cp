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
    int min_v = (int)1e9;
    for(int i = 0; i < N; i++) {
        int M;
        std::cin >> M;

        A[i].resize(M);
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            min_v = std::min(min_v, A[i][j]);
        }
    }

    std::vector<std::pair<int, int>> save_min(N);
    int min_g1 = (int)1e9;
    int min_g2 = (int)1e9;
    for(int i = 0; i < N; i++) {
        int min1 = (int)1e9;
        int min2 = (int)1e9;
        for(int x : A[i]) {
            if(x < min1) {
                min2 = min1;
                min1 = x;
            } else if(x < min2) {
                min2 = x;
            }
        }

        save_min[i] = {min1, min2};
        min_g1 = std::min(min_g1, min1);
        min_g2 = std::min(min_g2, min2);
    }

    int t = -1;
    for(int i = 0; i < N; i++) {
        if(min_g1 == save_min[i].first && min_g1 == save_min[i].second) {
            t = i;
            break;
        }
    }

    if(t == -1) {
        for(int i = 0; i < N; i++) {
            if(min_g2 == save_min[i].second) {
                t = i;
                break;
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        if(i == t) {
            ans += min_g1;
        } else {
            ans += save_min[i].second;
        }
    }

    std::cout << ans << '\n';
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
