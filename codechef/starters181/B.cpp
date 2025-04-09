#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }


    std::vector<std::vector<int>> a(N, std::vector<int>(M, 0));

    auto check = [&]() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                for(int d = 0; d < 4; d++) {
                    int ni = i + DR[d];
                    int nj = j + DC[d];
                    if(ni >= 0 && nj >= 0 && ni < N && nj < M) {
                        if(std::abs(a[i][j] - a[ni][nj]) != 1) {
                            return false;
                        }
                    }
                }

                if(i - 1 >= 0 && i + 1 < N) {
                    int sum = a[i - 1][j] + a[i + 1][j];
                    if(sum % 2 != 0 || sum / 2 != a[i][j]) {
                        return false;
                    }
                }

                if(j - 1 >= 0 && j + 1 < M) {
                    int sum = a[i][j - 1] + a[i][j + 1];
                    if(sum % 2 != 0 || sum / 2 != a[i][j]) {
                        return false;
                    }
                }
            }
        }

        return true;
    };

    auto print = [&]() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                std::cout << a[i][j] << " \n"[j == M - 1];
            }
        }
    };

    int ans = N * M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            a[i][j] = A[i][j]; 
            int cnt = 0;

            // increasing on row
            for(int c = j + 1; c < M; c++) {
                a[i][c] = a[i][c - 1] + 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }
            for(int c = j - 1; c >= 0; c--) {
                a[i][c] = a[i][c + 1] - 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }

            for(int r = i + 1; r < N; r++) {
                a[r][j] = a[r - 1][j] - 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = i - 1; r >= 0; r--) {
                a[r][j] = a[r + 1][j] + 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = 0; r < N; r++) {
                if(r == i) {
                    continue;
                }
                for(int c = j - 1; c >= 0; c--) {
                    a[r][c] = a[r][c + 1] - 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
                for(int c = j + 1; c < M; c++) {
                    a[r][c] = a[r][c - 1] + 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
            }  

            //print();
            //assert(check());

            ans = std::min(ans, cnt);

            cnt = 0; 
            for(int c = j + 1; c < M; c++) {
                a[i][c] = a[i][c - 1] + 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }
            for(int c = j - 1; c >= 0; c--) {
                a[i][c] = a[i][c + 1] - 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }

            for(int r = i + 1; r < N; r++) {
                a[r][j] = a[r - 1][j] + 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = i - 1; r >= 0; r--) {
                a[r][j] = a[r + 1][j] - 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = 0; r < N; r++) {
                if(r == i) {
                    continue;
                }
                for(int c = j - 1; c >= 0; c--) {
                    a[r][c] = a[r][c + 1] - 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
                for(int c = j + 1; c < M; c++) {
                    a[r][c] = a[r][c - 1] + 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
            }  
            
            //assert(check());
            ans = std::min(ans, cnt);

            // decreasing on row;
            cnt = 0;
            for(int c = j + 1; c < M; c++) {
                a[i][c] = a[i][c - 1] - 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }
            for(int c = j - 1; c >= 0; c--) {
                a[i][c] = a[i][c + 1] + 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }

            for(int r = i + 1; r < N; r++) {
                a[r][j] = a[r - 1][j] + 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = i - 1; r >= 0; r--) {
                a[r][j] = a[r + 1][j] - 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = 0; r < N; r++) {
                if(r == i) {
                    continue;
                }
                for(int c = j - 1; c >= 0; c--) {
                    a[r][c] = a[r][c + 1] + 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
                for(int c = j + 1; c < M; c++) {
                    a[r][c] = a[r][c - 1] - 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
            }  
            
            //print();
            //assert(check());
            ans = std::min(ans, cnt);

            cnt = 0;
            for(int c = j + 1; c < M; c++) {
                a[i][c] = a[i][c - 1] - 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }
            for(int c = j - 1; c >= 0; c--) {
                a[i][c] = a[i][c + 1] + 1;
                if(a[i][c] != A[i][c]) {
                    cnt += 1;
                }
            }

            for(int r = i + 1; r < N; r++) {
                a[r][j] = a[r - 1][j] - 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = i - 1; r >= 0; r--) {
                a[r][j] = a[r + 1][j] + 1;
                if(a[r][j] != A[r][j]) {
                    cnt += 1;
                }
            }

            for(int r = 0; r < N; r++) {
                if(r == i) {
                    continue;
                }
                for(int c = j - 1; c >= 0; c--) {
                    a[r][c] = a[r][c + 1] + 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
                for(int c = j + 1; c < M; c++) {
                    a[r][c] = a[r][c - 1] - 1;
                    if(a[r][c] != A[r][c]) {
                        cnt += 1;
                    }
                }
            }  

            //assert(check());
            ans = std::min(ans, cnt);
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
