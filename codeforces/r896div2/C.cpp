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
    int N, M;
    std::cin >> N >> M;

    if(M == 1) {
        std::cout << 0 << '\n';
        for(int i = 0; i < N; i++) {
            std::cout << 0 << '\n';
        }
        return;
    }

    if(N == 1) {
        std::cout << 2 << '\n';
        for(int i = 0; i < M; i++) {
            std::cout << i << " \n"[i == M - 1];
        }
        return;
    }

    std::vector<int> mex(M, -1);
    std::vector<std::vector<int>> ans(N, std::vector<int>(M, -1));
    int max_mex = 0;

    if(N < M) {
        max_mex = N + 1;
        for(int i = 0; i < M; i++) {
            int k = 0;
            for(int j = i; j < N && k < M - i; j++, k++) {
                ans[j][i] = k;
            }
            mex[i] = k;
        }
    } else {
        max_mex = M;
        for(int i = 0; i < M; i++) {
            int k = 0;
            for(int j = i; j < N && k < M - 1 - i; j++, k++) {
                ans[j][i] = k;
            }
            mex[i] = k;
        }
    }

    for(int i = 0; i < N; i++) {
        std::set<int> s;
        for(int j = 0; j < M; j++) {
            s.insert(j);
        }

        for(int j = 0; j < M; j++) {
            if(ans[i][j] != -1) {
                s.erase(ans[i][j]);
            }
        }

        for(int j = 0; j < M; j++) {
            if(ans[i][j] == -1) {
                int v = *s.begin();
                if(mex[j] == v) {
                    v = *s.upper_bound(v);
                }

                ans[i][j] = v;
                s.erase(v);
            }
        }
    }

    std::cout << max_mex << '\n';
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << ans[i][j] << " \n"[j == M - 1];
        }
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
