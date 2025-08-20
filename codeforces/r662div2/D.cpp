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

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> left(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> right(N, std::vector<int>(M, 0));

    for(int r = 0; r < N; r++) {
        int x = -1;
        int f = 0;
        for(int c = 0; c < M; c++) {
            if(A[r][c] - 'a' == x) {
                f += 1;
            } else {
                f = 1;
                x = A[r][c] - 'a';
            }
            left[r][c] = f - 1;
        }
    }

    for(int r = 0; r < N; r++) {
        int x = -1;
        int f = 0;
        for(int c = M - 1; c >= 0; c--) {
            if(A[r][c] - 'a' == x) {
                f += 1;
            } else {
                f = 1;
                x = A[r][c] - 'a';
            }
            right[r][c] = f - 1;
        }
    }

    std::vector<std::vector<int>> dp1(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> dp2(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> ds(N, std::vector<int>(M, 0));
    
    int64_t ans = N * M;
    for(int r = N - 1; r >= 0; r--) {
        for(int c = 0; c < M; c++) {
            int h = 0;
            if(r + 1 < N - 1 && A[r + 1][c] == A[r][c]) {
                h = dp2[r + 1][c];
            }

            while(r - h >= 0) {
                if(A[r - h][c] == A[r][c] && left[r - h][c] >= h && right[r - h][c] >= h) {
                    h += 1;
                } else {
                    break;
                }
            }
            dp2[r][c] = h - 1;
        }
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            int h = 0;
            if(r - 1 >= 0 && A[r - 1][c] == A[r][c]) {
                h = dp1[r - 1][c];                  
            }

            while(r + h < N) {
                if(A[r + h][c] == A[r][c] && left[r + h][c] >= h && right[r + h][c] >= h) {
                    h += 1;
                } else {
                    break;
                }
            }
            dp1[r][c] = h - 1;
        }
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            int from = (r - 1 >= 0 && A[r - 1][c] == A[r][c]) ? r + dp1[r - 1][c] : r + 1;
            int to = r + dp1[r][c];

            for(int i = from; i <= to; i++) {
                int rr = r + (i - r) * 2;
                if(rr < N && dp2[rr][c] >= i - r) {
                    ds[i][c] = std::max(ds[i][c], (i - r) * 2 + 1);
                } else {
                    dp1[r][c] = i - r - 1;
                    break;
                }
            }
        }
    }

    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            ans += ds[r][c] / 2;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
