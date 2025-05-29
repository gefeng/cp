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
    
    if(N < 3) {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, 0));
    ans[0][0] = N * N;
    ans[0][1] = N * N - 4;
    ans[0][2] = N * N - 3;
    ans[1][0] = N * N - 2;
    ans[1][1] = N * N - 7;
    ans[1][2] = N * N - 1;
    ans[2][0] = N * N - 8;
    ans[2][1] = N * N - 6;
    ans[2][2] = N * N - 5;
    
    int r = N % 2 == 0 ? 0 : N - 1;
    int c = N % 2 == 0 ? N - 1 : 0;
    int now = 1; 
    if(N % 2 == 0) {
        while(r > 2 || c > 2) {
            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                r += 1;
                if(r == N || ans[r][c]) {
                    r -= 1;
                    c -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                c -= 1;
                if(c < 0 || ans[r][c]) {
                    c += 1;
                    r -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                c += 1;
                if(c == N || ans[r][c]) {
                    r -= 1;
                    c -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                r -= 1;
                if(r < 0 || ans[r][c]) {
                    r += 1;
                    c -= 1;
                    break;
                }
            }
        }
    } else {
        while(r > 2 || c > 2) {
            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                c += 1;
                if(c == N || ans[r][c]) {
                    c -= 1;
                    r -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                r -= 1;
                if(r < 0 || ans[r][c]) {
                    r += 1;
                    c -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                r += 1;
                if(r == N || ans[r][c]) {
                    r -= 1;
                    c -= 1;
                    break;
                }
            }

            while(r > 2 || c > 2) {
                ans[r][c] = now++;
                c -= 1;
                if(c < 0 || ans[r][c]) {
                    c += 1;
                    r -= 1;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cout << ans[i][j] << " \n"[j == N - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
