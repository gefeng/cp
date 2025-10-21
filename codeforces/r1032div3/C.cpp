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
    int max_v = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
            max_v = std::max(max_v, A[i][j]);
        }
    }

    std::vector<int> row(N, 0);
    std::vector<int> col(M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == max_v) {
                row[i] += 1;
                col[j] += 1;
            }
        }
    }

    int r = -1;
    int c = -1;
    int max_r = 0;
    int max_c = 0;
    for(int i = 0; i < N; i++) {
        if(row[i] > max_r) {
            max_r = row[i];
            r = i;
        }
    }

    for(int i = 0; i < M; i++) {
        if(col[i] > max_c) {
            max_c = col[i];
            c = i;
        }
    }

    int pre = -1;
    bool ok = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == max_v && i != r) {
                if(pre != -1 && j != pre) {
                    ok = false;
                }
                pre = j;
            }
        }
    }

    if(ok) {
        std::cout << max_v - 1 << '\n';
        return;
    }

    pre = -1;
    ok = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] == max_v && j != c) {
                if(pre != -1 && i != pre) {
                    ok = false;
                }
                pre = i;
            }
        }
    }

    std::cout << (ok ? max_v - 1 : max_v) << '\n';
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
