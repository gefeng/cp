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

    std::vector<std::vector<int>> seq = {
        {},
        {6, 11, 0},
        {12, 7, 0}, 
        {13, 0},
        {3, 13, 0},
        {8, 6, 13, 0},
        {11, 0},
        {0},
        {6, 13, 0},
        {7, 0},
        {4, 3, 13, 0},
        {0},
        {7, 0},
        {0},
        {0},
        {2, 12, 11, 0}
    };

    std::vector<std::vector<int>> ans;

    auto flip = [&](int x_1, int y_1, int x_2, int y_2, int x_3, int y_3) {
        ans.push_back({x_1, y_1, x_2, y_2, x_3, y_3}); 
        A[x_1][y_1] = char(((A[x_1][y_1] - '0') ^ 1) + '0');
        A[x_2][y_2] = char(((A[x_2][y_2] - '0') ^ 1) + '0');
        A[x_3][y_3] = char(((A[x_3][y_3] - '0') ^ 1) + '0');
    };

    auto apply = [&](int from, int to, int r, int c) {
        std::vector<int> cells;
        for(int i = 0; i < 4; i++) {
            int b_1 = from & (1 << i) ? 1 : 0;
            int b_2 = to & (1 << i) ? 1 : 0;
            if(b_1 != b_2) {
                if(i == 0) {
                    cells.push_back(r + 1);
                    cells.push_back(c);
                } else if(i == 1) {
                    cells.push_back(r + 1);
                    cells.push_back(c + 1);
                } else if(i == 2) {
                    cells.push_back(r);
                    cells.push_back(c + 1);
                } else {
                    cells.push_back(r);
                    cells.push_back(c);
                }
            }
        } 
        flip(cells[0], cells[1], cells[2], cells[3], cells[4], cells[5]);
    };

    auto add_seq = [&](int x, int r, int c) {
        if(x == 0) {
            return;
        } 

        int pre = x;
        for(int s : seq[x]) {
            apply(pre, s, r, c);
            pre = s;
        }
    };

    if(N % 2 == 1) {
        for(int i = 0; i < M; i += 2) {
            if(i + 1 == M) {
                if(A[N - 1][i] == '1') {
                    flip(N - 2, i - 1, N - 2, i, N - 1, i);
                }
            } else {
                if(A[N - 1][i] == '0' && A[N - 1][i + 1] == '0') {
                    continue;
                }
                if(A[N - 1][i] == '1' && A[N - 1][i + 1] == '1') {
                    flip(N - 2, i, N - 1, i, N - 1, i + 1);  
                    continue;
                }
                if(A[N - 1][i] == '0' && A[N - 1][i + 1] == '1') {
                    flip(N - 2, i, N - 2, i + 1, N - 1, i + 1);
                    continue;
                }
                flip(N - 2, i, N - 2, i + 1, N - 1, i);
            }
        }
        N -= 1;
    }

    if(M % 2 == 1) {
        for(int i = 0; i < N; i += 2) {
            if(i + 1 == N) {
                continue;
            }
            if(A[i][M - 1] == '0' && A[i + 1][M - 1] == '0') {
                continue;
            }
            if(A[i][M - 1] == '1' && A[i + 1][M - 1] == '1') {
                flip(i, M - 2, i, M - 1, i + 1, M - 1);
                continue;
            }
            if(A[i][M - 1] == '0' && A[i + 1][M - 1] == '1') {
                flip(i, M - 2, i + 1, M - 2, i + 1, M - 1);
                continue;
            }
            flip(i + 1, M - 2, i, M - 2, i, M - 1);
        }
        M -= 1;
    }

    for(int i = 0; i < N; i += 2) {
        for(int j = 0; j < M; j += 2) {
            int x = (A[i][j] - '0') << 3;
            x |= (A[i][j + 1] - '0') << 2;
            x |= (A[i + 1][j + 1] - '0') << 1;
            x |= A[i + 1][j] - '0';

            add_seq(x, i, j);
        }
    }

    int size = ans.size();
    //assert(size <= N * M);
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 6; j++) {
            std::cout << ans[i][j] + 1 << " \n"[j == 5];
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
